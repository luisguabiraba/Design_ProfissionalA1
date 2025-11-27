CREATE SCHEMA seguranca;

CREATE TABLE seguranca.cidadao (
    id_cidadao SERIAL PRIMARY KEY,
    nome VARCHAR(100) NOT NULL,
    cpf CHAR(11) UNIQUE NOT NULL,
    contato VARCHAR(50)
);

CREATE TABLE seguranca.unidade_policial (
    id_unidade SERIAL PRIMARY KEY,
    nome VARCHAR(100) NOT NULL,
    telefone VARCHAR(20),
    endereco VARCHAR(150),
    area_atuacao VARCHAR(100)
);

CREATE TABLE seguranca.ocorrencia (
    id_ocorrencia SERIAL PRIMARY KEY,
    id_cidadao INT NOT NULL,
    id_unidade INT NOT NULL,
    data_hora TIMESTAMP NOT NULL,
    descricao TEXT,
    FOREIGN KEY (id_cidadao) REFERENCES seguranca.cidadao (id_cidadao),
    FOREIGN KEY (id_unidade) REFERENCES seguranca.unidade_policial (id_unidade)
);

CREATE TABLE seguranca.agente_seguranca (
    id_agente SERIAL PRIMARY KEY,
    id_unidade INT NOT NULL,
    matricula VARCHAR(20) UNIQUE NOT NULL,
    nome VARCHAR(100) NOT NULL,
    funcao VARCHAR(50),
    FOREIGN KEY (id_unidade) REFERENCES seguranca.unidade_policial (id_unidade)
);

CREATE TABLE seguranca.zona_risco (
    id_zona SERIAL PRIMARY KEY,
    id_unidade INT NOT NULL,
    nome_zona VARCHAR(100) NOT NULL,
    latitude DECIMAL(10,6),
    longitude DECIMAL(10,6),
    FOREIGN KEY (id_unidade) REFERENCES seguranca.unidade_policial (id_unidade)
);

CREATE TABLE seguranca.dispositivo_monitoramento (
    id_dispositivo SERIAL PRIMARY KEY,
    id_zona INT,
    numero_serie VARCHAR(50) UNIQUE NOT NULL,
    tipo VARCHAR(30) CHECK (tipo IN ('Câmera', 'Sensor', 'Alarme', 'Drone', 'Outro')),
    latitude DECIMAL(10,6),
    longitude DECIMAL(10,6),
    FOREIGN KEY (id_zona) REFERENCES seguranca.zona_risco (id_zona)
);

CREATE TABLE seguranca.detecta (
    id_unidade INT NOT NULL,
    id_dispositivo INT NOT NULL,
    PRIMARY KEY (id_unidade, id_dispositivo),
    FOREIGN KEY (id_unidade) REFERENCES seguranca.unidade_policial (id_unidade),
    FOREIGN KEY (id_dispositivo) REFERENCES seguranca.dispositivo_monitoramento (id_dispositivo)
);

CREATE TABLE seguranca.patrulhamento (
    id_patrulhamento SERIAL PRIMARY KEY,
    data_hora_inicio TIMESTAMP NOT NULL,
    data_hora_fim TIMESTAMP,
    rota_realizada TEXT,
    viatura_utilizada VARCHAR(50)
);

CREATE TABLE seguranca.participa (
    id_agente INT NOT NULL,
    id_patrulhamento INT NOT NULL,
    PRIMARY KEY (id_agente, id_patrulhamento),
    FOREIGN KEY (id_agente) REFERENCES seguranca.agente_seguranca (id_agente),
    FOREIGN KEY (id_patrulhamento) REFERENCES seguranca.patrulhamento (id_patrulhamento)
);

CREATE TABLE seguranca.alerta_tempo_real (
    id_alerta SERIAL PRIMARY KEY,
    data_hora TIMESTAMP NOT NULL,
    descricao TEXT
);

CREATE TABLE seguranca.gera (
    id_dispositivo INT NOT NULL,
    id_alerta INT NOT NULL,
    PRIMARY KEY (id_dispositivo, id_alerta),
    FOREIGN KEY (id_dispositivo) REFERENCES seguranca.dispositivo_monitoramento (id_dispositivo),
    FOREIGN KEY (id_alerta) REFERENCES seguranca.alerta_tempo_real (id_alerta)
);

CREATE TABLE seguranca.chamado (
    id_chamado SERIAL PRIMARY KEY,
    id_alerta INT UNIQUE NOT NULL,
    id_patrulhamento INT UNIQUE NOT NULL,
    FOREIGN KEY (id_alerta) REFERENCES seguranca.alerta_tempo_real (id_alerta),
    FOREIGN KEY (id_patrulhamento) REFERENCES seguranca.patrulhamento (id_patrulhamento)
);

CREATE TABLE seguranca.logs_sistema (
    id_log SERIAL PRIMARY KEY,
    id_patrulhamento INT NOT NULL,
    id_usuario_acao VARCHAR(50),
    timestamp_acao TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    descricao_acao TEXT,
    FOREIGN KEY (id_patrulhamento) REFERENCES seguranca.patrulhamento (id_patrulhamento)
);



INSERT INTO seguranca.cidadao (nome, cpf, contato) VALUES
('Carlos Almeida', '56945123178', '(61) 99999-1111'),
('Mariana Souza', '98765432190', '(61) 98888-2222'),
('João Pereira', '32165498704', '(61) 97777-3333');

INSERT INTO seguranca.unidade_policial (nome, telefone, endereco, area_atuacao) VALUES
('1ª Delegacia Central', '(61) 4002-8922', 'Eixo Monumental, Brasília', 'Centro'),
('2ª Unidade Norte', '(61) 3555-7878', 'Av. W3 Norte, Brasília', 'Asa Norte');

INSERT INTO seguranca.ocorrencia (id_cidadao, id_unidade, data_hora, descricao) VALUES
(1, 1, '2025-10-10 06:38:55', 'Furto de veículo na região central.'),
(2, 1, '2025-12-10 17:48:21', 'Assalto à mão armada próximo à praça.'),
(3, 2, '2025-10-15 23:01:41', 'Distúrbio em via pública.');

INSERT INTO seguranca.agente_seguranca (id_unidade, matricula, nome, funcao) VALUES
(1, 'AG001', 'Erick Silva', 'Investigador'),
(1, 'AG002', 'Aline Costa', 'Delegada'),
(2, 'AG003', 'Gustavo Lima', 'Patrulheiro');

INSERT INTO seguranca.zona_risco (id_unidade, nome_zona, latitude, longitude) VALUES
(1, 'Plano Piloto', -23.550520, -46.633308),
(2, 'Asa Norte', -23.480100, -46.620700);

INSERT INTO seguranca.dispositivo_monitoramento (id_zona, numero_serie, tipo, latitude, longitude) VALUES
(1, 'CAM-001', 'Câmera', -23.550500, -46.633300),
(1, 'ALR-002', 'Alarme', -23.550520, -46.633250),
(2, 'SEN-003', 'Sensor', -23.480000, -46.620600);

INSERT INTO seguranca.detecta (id_unidade, id_dispositivo) VALUES
(1, 1),
(1, 2),
(2, 3);

INSERT INTO seguranca.patrulhamento 
(data_hora_inicio, data_hora_fim, rota_realizada, viatura_utilizada) 
VALUES
('2025-10-12 09:48:51', '2025-10-12 11:32:11', 'Rota A: Centro - Praça Central', 'Viatura 01'),
('2025-10-15 17:32:21', '2025-10-15 18:30:43', 'Rota B: Asa Norte - Av. W3 Norte', 'Viatura 02');

INSERT INTO seguranca.participa (id_agente, id_patrulhamento) VALUES
(1, 1),
(2, 1),
(3, 2);

INSERT INTO seguranca.alerta_tempo_real (data_hora, descricao) VALUES
('2025-10-10 06:38:55', 'Movimento suspeito detectado na Praça Central.'),
('2025-12-10 17:48:21', 'Sensor detectou ruído anormal na Av. W3 Norte.');

INSERT INTO seguranca.gera (id_dispositivo, id_alerta) VALUES
(1, 1),
(3, 2);

INSERT INTO seguranca.chamado (id_alerta, id_patrulhamento) VALUES
(1, 1),
(2, 2);

INSERT INTO seguranca.logs_sistema (id_patrulhamento, id_usuario_acao, descricao_acao) VALUES
(1, 'admin', 'Início de patrulhamento registrado.'),
(1, 'erick.silva', 'Chegada à Praça Central confirmada.'),
(2, 'gustavo.lima', 'Encerramento de patrulhamento registrado.');




