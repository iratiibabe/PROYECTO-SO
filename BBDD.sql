DROP DATABASE IF EXISTS Juego;
CREATE DATABASE Juego;

USE Juego;

CREATE TABLE Jugador (
	Id_jugador INTEGER PRIMARY KEY NOT NULL,	
	Nombre VARCHAR(60) NOT NULL,	
	Puntos INT NOT NULL,
	Contraseña VARCHAR(60) NOT NULL
)ENGINE = InnoDB;

CREATE TABLE Partida (
    Id_partida INT PRIMARY KEY NOT NULL,
    Ganador INT,
    FOREIGN KEY (Ganador) REFERENCES Jugador(Id_jugador) 
) ENGINE = InnoDB;

CREATE TABLE Participacion (
    Id_partida INT NOT NULL,
    Id_jugador INT NOT NULL,
    PRIMARY KEY (Id_partida, Id_jugador),  
    FOREIGN KEY (Id_partida) REFERENCES Partida(Id_partida),
    FOREIGN KEY (Id_jugador) REFERENCES Jugador(Id_jugador)
) ENGINE = InnoDB;

INSERT INTO Jugador VALUES(1,'Juan',25,'hola');
INSERT INTO Jugador VALUES(2,'Maria',30,'casa');
INSERT INTO Jugador VALUES(3,'Jose',50,'avion');
INSERT INTO Jugador VALUES(4,'Lucia',40,'constraseña');
INSERT INTO Jugador VALUES(5,'Pablo',55,'juego');

INSERT INTO Partida VALUES(1,5);
INSERT INTO Partida VALUES(2,3); 
INSERT INTO Partida VALUES(3,5); 

INSERT INTO Participacion VALUES(1,2);
INSERT INTO Participacion VALUES(1,4);
INSERT INTO Participacion VALUES(1,5);

INSERT INTO Participacion VALUES(2,3);
INSERT INTO Participacion VALUES(2,2);

INSERT INTO Participacion VALUES(3,1);
INSERT INTO Participacion VALUES(3,2);
INSERT INTO Participacion VALUES(3,3);
INSERT INTO Participacion VALUES(3,4);
INSERT INTO Participacion VALUES(3,5);


 

