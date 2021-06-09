-- MySQL dump 10.13  Distrib 8.0.23, for Win64 (x86_64)
--
-- Host: localhost    Database: db_punto_venta
-- ------------------------------------------------------
-- Server version	8.0.23

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!50503 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `clientes`
--

DROP TABLE IF EXISTS `clientes`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `clientes` (
  `id_cliente` int NOT NULL AUTO_INCREMENT,
  `nombres` varchar(60) DEFAULT NULL,
  `apellidos` varchar(60) DEFAULT NULL,
  `nit` varchar(12) NOT NULL,
  `genero` int DEFAULT NULL,
  `telefono` varchar(25) DEFAULT NULL,
  `correo_electronico` varchar(45) DEFAULT NULL,
  `fecha_ingreso` datetime DEFAULT CURRENT_TIMESTAMP,
  PRIMARY KEY (`id_cliente`)
) ENGINE=InnoDB AUTO_INCREMENT=17 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `clientes`
--

LOCK TABLES `clientes` WRITE;
/*!40000 ALTER TABLE `clientes` DISABLE KEYS */;
INSERT INTO `clientes` VALUES (1,'juan jose','diaz sol','323423',0,'342334','juan@hotmail.com','2021-02-03 12:34:34'),(2,'rosa maria','lopez lopez','23454',1,'435423','rosa@otmail.com','2021-04-02 04:20:34'),(3,'lisbeth andreina','carmaja sino','4565745',1,'908765','lis@otmail.com','2021-04-15 08:00:00'),(4,'david mario','ortiz morales','435623',0,'8765423','dav@otmail.com','2021-04-20 18:00:00'),(5,'mariana azucena','garrido gonzales','76543234',1,'3452343','mar@otmail.com','2021-04-14 14:00:00'),(7,'juan jose','diaz sol','323423',0,'342334','juan@hotmail.com','2021-03-03 12:00:00'),(8,'consumidor final','cf','cf',0,'0','cf','2021-02-02 12:00:00'),(9,'adriana','muralles','202021',1,'2390430','adri@gmail.com','2021-02-02 12:00:00'),(11,'melani sara','lopez morales','909023',1,'439812','mel@gmail.com','2021-02-03 12:00:00'),(14,'jeeff','goccc','032312',0,'23443','ge@gmail.com','2021-02-02 12:00:00'),(15,'manuel','gds','430000',1,'3232','dfsdf@gmail.com','2021-06-03 05:09:58'),(16,'analu','sdfh','102030',1,'344323','an@gmail.com','2021-06-03 05:12:41');
/*!40000 ALTER TABLE `clientes` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `compras`
--

DROP TABLE IF EXISTS `compras`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `compras` (
  `id_compra` int NOT NULL AUTO_INCREMENT,
  `no_orden_compra` int DEFAULT NULL,
  `id_proveedor` int NOT NULL,
  `fecha_orden` date DEFAULT NULL,
  `fecha_ingreso` datetime NOT NULL DEFAULT CURRENT_TIMESTAMP,
  PRIMARY KEY (`id_compra`),
  KEY `id_compra_compra_proveedores_idx` (`id_proveedor`),
  CONSTRAINT `id_compra_compra_proveedores` FOREIGN KEY (`id_proveedor`) REFERENCES `proveedores` (`id_proveedor`) ON UPDATE CASCADE
) ENGINE=InnoDB AUTO_INCREMENT=10 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `compras`
--

LOCK TABLES `compras` WRITE;
/*!40000 ALTER TABLE `compras` DISABLE KEYS */;
INSERT INTO `compras` VALUES (1,2020,3,'2021-03-01','2021-03-10 12:00:00'),(2,2021,5,'2021-02-01','2021-03-10 08:00:00'),(3,2022,1,'2021-03-01','2021-03-10 16:20:00'),(4,2023,2,'2021-03-10','2021-03-20 09:10:00'),(5,2024,4,'2021-03-10','2021-03-26 09:40:00'),(6,2025,6,'2021-02-02','2021-05-27 12:51:40'),(7,2026,5,'2021-02-02','2021-05-27 13:00:05'),(8,2027,5,'2021-02-02','2021-05-27 14:04:13'),(9,2028,4,'2021-02-02','2021-05-27 14:22:03');
/*!40000 ALTER TABLE `compras` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `compras_detalle`
--

DROP TABLE IF EXISTS `compras_detalle`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `compras_detalle` (
  `id_compra_detalle` bigint NOT NULL AUTO_INCREMENT,
  `id_compra` int NOT NULL,
  `id_producto` int NOT NULL,
  `cantidad` int DEFAULT NULL,
  `precio_costo_unitario` decimal(8,2) DEFAULT NULL,
  `subtotal` decimal(8,2) DEFAULT NULL,
  PRIMARY KEY (`id_compra_detalle`),
  KEY `id_compra_detalle_compra_detalle_compras_idx` (`id_compra`),
  KEY `id_compra_detalle_compra_detalle_productos_idx` (`id_producto`),
  CONSTRAINT `id_compra_detalle_compra_detalle_compras` FOREIGN KEY (`id_compra`) REFERENCES `compras` (`id_compra`) ON UPDATE CASCADE,
  CONSTRAINT `id_compra_detalle_compra_detalle_productos` FOREIGN KEY (`id_producto`) REFERENCES `productos` (`id_producto`) ON UPDATE CASCADE
) ENGINE=InnoDB AUTO_INCREMENT=16 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `compras_detalle`
--

LOCK TABLES `compras_detalle` WRITE;
/*!40000 ALTER TABLE `compras_detalle` DISABLE KEYS */;
INSERT INTO `compras_detalle` VALUES (1,1,2,10,10.00,NULL),(2,2,1,10,5.00,NULL),(3,3,3,20,12.00,NULL),(4,4,4,40,1.00,NULL),(5,5,5,50,1.00,NULL),(6,6,2,3,3.00,9.00),(7,6,3,4,5.00,20.00),(8,7,3,4,3.00,12.00),(9,7,2,3,3.00,9.00),(10,8,2,3,4.00,12.00),(11,8,2,3,4.00,12.00),(12,8,3,4,5.00,20.00),(13,9,2,10,5.00,50.00),(14,9,4,10,2.00,20.00),(15,9,1,10,2.50,25.00);
/*!40000 ALTER TABLE `compras_detalle` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `empleados`
--

DROP TABLE IF EXISTS `empleados`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `empleados` (
  `id_empleado` int NOT NULL AUTO_INCREMENT,
  `nombres` varchar(60) NOT NULL,
  `apellidos` varchar(60) NOT NULL,
  `direccion` varchar(80) NOT NULL,
  `telefono` varchar(25) NOT NULL,
  `dpi` varchar(15) NOT NULL,
  `genero` int NOT NULL,
  `fecha_nacimiento` date NOT NULL,
  `id_puesto` smallint NOT NULL,
  `fecha_inicio_labores` date NOT NULL,
  `fecha_ingreso` datetime NOT NULL,
  PRIMARY KEY (`id_empleado`),
  KEY `id_empleado_empleado_puestos_idx` (`id_puesto`),
  CONSTRAINT `id_empleado_empleado_puestos` FOREIGN KEY (`id_puesto`) REFERENCES `puestos` (`id_puesto`) ON UPDATE CASCADE
) ENGINE=InnoDB AUTO_INCREMENT=10 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `empleados`
--

LOCK TABLES `empleados` WRITE;
/*!40000 ALTER TABLE `empleados` DISABLE KEYS */;
INSERT INTO `empleados` VALUES (1,'Rosy Marilu','Xicay Galvez','san antonio callejon2 casa 12','32345754','32981209',1,'2000-04-10',4,'2021-01-05','2021-01-10 00:00:00'),(2,'Marta Andrea','Gomez Lopez','antigua 3era avenida','3443565','233445664',1,'1997-10-11',2,'2020-02-05','2021-02-16 08:00:00'),(3,'Esteban andres','Perez solares','antigua 5ta avenida','23344556','009233223',0,'1990-05-21',3,'2020-02-05','2021-02-16 08:00:00'),(4,'Julio Hugo','Flores Morales','santa ana casa no3','5566343','2345323',0,'1999-03-21',3,'2020-02-05','2021-02-16 08:00:00'),(5,'Eduardo Andres','Reyes Garcia','antigua 5ta calle no4','34320129','239012943',0,'1999-04-15',1,'2020-02-05','2021-02-16 08:00:00'),(6,'Maria Alejandra','lopez morales','antifua','322323','323234',1,'2000-01-01',1,'2021-02-02','2021-03-03 12:00:00'),(7,'azzzz','rodssss','ciudad','2345','343434',1,'2000-02-01',2,'2021-02-02','2021-02-03 12:00:00'),(8,'yulisaaa','lopez','antigua','2332','3456',1,'2000-02-02',1,'2021-02-03','2021-02-03 12:00:00'),(9,'mmmmm','sdasd','ciudad','2334554','2121221',0,'1999-02-02',2,'2021-02-02','2021-03-02 12:00:00');
/*!40000 ALTER TABLE `empleados` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `marcas`
--

DROP TABLE IF EXISTS `marcas`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `marcas` (
  `id_marca` smallint NOT NULL AUTO_INCREMENT,
  `marca` varchar(50) NOT NULL,
  PRIMARY KEY (`id_marca`)
) ENGINE=InnoDB AUTO_INCREMENT=8 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `marcas`
--

LOCK TABLES `marcas` WRITE;
/*!40000 ALTER TABLE `marcas` DISABLE KEYS */;
INSERT INTO `marcas` VALUES (1,'oreo'),(2,'pepsi'),(3,'coca cola'),(4,'maggi'),(5,'kit kat'),(7,'nestle');
/*!40000 ALTER TABLE `marcas` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `productos`
--

DROP TABLE IF EXISTS `productos`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `productos` (
  `id_producto` int NOT NULL AUTO_INCREMENT,
  `producto` varchar(50) DEFAULT NULL,
  `id_marca` smallint NOT NULL,
  `descripcion` varchar(100) DEFAULT NULL,
  `precio_costo` decimal(8,2) DEFAULT NULL,
  `precio_venta` decimal(8,2) DEFAULT NULL,
  `existencia` int DEFAULT NULL,
  `fecha_ingreso` datetime DEFAULT NULL,
  PRIMARY KEY (`id_producto`),
  KEY `id_producto_producto_marcas_idx` (`id_marca`),
  CONSTRAINT `id_producto_producto_marcas` FOREIGN KEY (`id_marca`) REFERENCES `marcas` (`id_marca`) ON UPDATE CASCADE
) ENGINE=InnoDB AUTO_INCREMENT=8 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `productos`
--

LOCK TABLES `productos` WRITE;
/*!40000 ALTER TABLE `productos` DISABLE KEYS */;
INSERT INTO `productos` VALUES (1,'galletas',1,'sabor choloate 4 unidades',10.00,15.00,20,'2021-03-10 12:00:00'),(2,'gaseosa',2,'unidad de 3lts',10.00,16.00,30,'2021-03-10 08:00:00'),(3,'gaseosa',3,'unidad de 2.5lts',12.00,17.00,40,'2021-03-15 09:40:00'),(4,'sopas',4,'bolsas 200 grms',1.00,3.00,20,'2021-03-16 16:20:00'),(5,'chocolate',5,'sabor vainilla',1.00,3.00,50,'2021-03-20 09:10:00');
/*!40000 ALTER TABLE `productos` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `proveedores`
--

DROP TABLE IF EXISTS `proveedores`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `proveedores` (
  `id_proveedor` int NOT NULL AUTO_INCREMENT,
  `proveedor` varchar(60) NOT NULL,
  `nit` varchar(12) NOT NULL,
  `direccion` varchar(48) NOT NULL,
  `telefono` varchar(25) NOT NULL,
  PRIMARY KEY (`id_proveedor`)
) ENGINE=InnoDB AUTO_INCREMENT=7 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `proveedores`
--

LOCK TABLES `proveedores` WRITE;
/*!40000 ALTER TABLE `proveedores` DISABLE KEYS */;
INSERT INTO `proveedores` VALUES (1,'empresas s.a','343434','zona 12 capitalina','324323'),(2,'importadora s.d','343322','zona 11 capitalina ave.12','434534'),(3,'oreos s.a','343434','zona 10 ave 12 capitalina','434342'),(4,'productos ma','235456','ave 12 escuintla','4333234'),(5,'pesc s','32090090','san lucas 12 calle','78213243'),(6,'LSDF','345634','DSFKSDF','234567');
/*!40000 ALTER TABLE `proveedores` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `puestos`
--

DROP TABLE IF EXISTS `puestos`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `puestos` (
  `id_puesto` smallint NOT NULL AUTO_INCREMENT,
  `puesto` varchar(45) NOT NULL,
  PRIMARY KEY (`id_puesto`)
) ENGINE=InnoDB AUTO_INCREMENT=6 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `puestos`
--

LOCK TABLES `puestos` WRITE;
/*!40000 ALTER TABLE `puestos` DISABLE KEYS */;
INSERT INTO `puestos` VALUES (1,'gerente'),(2,'cajero'),(3,'seguridad'),(4,'contador'),(5,'conserje');
/*!40000 ALTER TABLE `puestos` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `ventas`
--

DROP TABLE IF EXISTS `ventas`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `ventas` (
  `id_venta` int NOT NULL AUTO_INCREMENT,
  `no_factura` int NOT NULL,
  `serie` char(1) DEFAULT NULL,
  `fecha_factura` date NOT NULL DEFAULT (curdate()),
  `id_cliente` int NOT NULL,
  `id_empleado` int NOT NULL,
  `fecha_ingreso` datetime NOT NULL DEFAULT CURRENT_TIMESTAMP,
  PRIMARY KEY (`id_venta`),
  KEY `id_venta_venta_empleados_idx` (`id_empleado`),
  KEY `id_venta_venta_clientes_idx` (`id_cliente`),
  CONSTRAINT `id_venta_venta_clientes` FOREIGN KEY (`id_cliente`) REFERENCES `clientes` (`id_cliente`),
  CONSTRAINT `id_venta_venta_empleados` FOREIGN KEY (`id_empleado`) REFERENCES `empleados` (`id_empleado`) ON UPDATE CASCADE
) ENGINE=InnoDB AUTO_INCREMENT=141 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `ventas`
--

LOCK TABLES `ventas` WRITE;
/*!40000 ALTER TABLE `ventas` DISABLE KEYS */;
INSERT INTO `ventas` VALUES (1,1001,'a','2021-03-10',1,2,'2021-03-10 00:00:00'),(2,1002,'a','2021-03-15',2,2,'2021-03-15 00:00:00'),(3,1003,'a','2021-03-20',3,5,'2021-03-20 00:00:00'),(4,1004,'a','2021-03-22',4,5,'2021-03-22 00:00:00'),(5,1005,'a','2021-03-25',5,5,'2021-03-25 00:00:00'),(6,1006,'a','2021-04-04',2,2,'2021-04-04 12:00:00'),(7,1007,'a','2021-04-04',7,2,'2021-04-04 12:10:00'),(8,1008,'a','2021-05-05',3,5,'2021-05-05 12:00:00'),(9,1009,'a','2021-02-02',3,3,'2021-02-02 00:00:00'),(10,12,'a','2021-02-02',3,2,'2021-02-02 00:00:00'),(11,1012,'a','2021-01-01',2,3,'2021-01-01 00:00:00'),(12,1013,'a','2021-05-05',1,2,'2021-05-05 00:00:00'),(13,1008,'a','2021-05-05',3,5,'2021-05-05 12:00:00'),(14,1008,'a','2021-05-05',3,5,'2021-05-05 12:00:00'),(15,1020,'a','2021-05-05',2,1,'2021-02-02 00:00:00'),(16,1021,'a','2021-01-01',2,3,'2021-02-02 00:00:00'),(17,1025,'a','2021-02-02',1,2,'2021-02-02 00:00:00'),(18,1029,'a','2021-02-02',1,2,'2021-02-02 00:00:00'),(19,1030,'a','2020-02-01',1,2,'2021-02-01 00:00:00'),(20,10100,'a','2020-02-02',4,2,'2021-02-02 00:00:00'),(21,1031,'a','2021-02-02',2,4,'2021-02-02 00:00:00'),(22,1,'a','2021-02-02',1,2,'2021-01-01 00:00:00'),(23,202,'a','2021-03-03',4,5,'2021-03-03 00:00:00'),(24,101,'a','2021-02-02',2,2,'2021-02-02 12:00:00'),(25,24,'a','2021-02-02',2,2,'2021-05-26 01:09:54'),(26,25,'a','2021-02-02',2,2,'2021-05-26 01:11:25'),(27,10101,'a','2021-09-09',2,3,'2021-05-26 01:12:57'),(28,10102,'a','2021-02-02',1,2,'2021-05-26 01:14:05'),(29,10103,'A','2021-02-02',2,2,'2021-05-26 14:20:22'),(30,10103,'A','2021-02-02',3,2,'2021-05-26 15:05:14'),(31,10104,'A','2021-02-02',3,2,'2021-05-26 15:16:29'),(32,10105,'A','2021-02-02',3,2,'2021-05-26 15:29:34'),(33,10106,'A','2021-01-01',3,3,'2021-05-26 15:37:44'),(34,10107,'A','2021-02-02',3,2,'2021-05-26 15:42:23'),(35,10108,'A','2021-05-04',3,3,'2021-05-26 15:48:44'),(36,10109,'A','2021-02-01',3,2,'2021-05-26 16:16:10'),(37,10110,'A','2021-02-02',3,2,'2021-05-26 16:20:07'),(38,10111,'A','2021-02-01',7,3,'2021-05-26 16:22:26'),(39,10112,'A','2021-02-01',3,3,'2021-05-26 16:26:27'),(41,10113,'A','2021-01-01',3,2,'2021-05-26 16:32:07'),(42,10114,'A','2021-01-01',3,3,'2021-05-26 16:34:23'),(43,10115,'A','2021-02-01',3,1,'2021-05-26 16:35:28'),(44,10116,'A','2021-02-02',3,3,'2021-05-26 16:50:42'),(45,10117,'A','2021-02-02',3,3,'2021-05-26 16:57:40'),(46,10118,'A','2021-02-01',3,2,'2021-05-26 17:06:10'),(47,10119,'A','2021-02-02',3,2,'2021-05-26 17:08:11'),(48,10120,'A','2021-02-01',3,3,'2021-05-26 17:11:11'),(49,10121,'A','2021-02-01',3,3,'2021-05-26 17:11:56'),(50,10122,'A','2021-02-02',3,2,'2021-05-26 17:27:54'),(51,10123,'A','2021-02-02',3,3,'2021-05-26 17:31:55'),(52,10124,'A','2021-02-02',3,2,'2021-05-26 18:11:50'),(53,10125,'A','2021-02-02',3,2,'2021-05-26 18:19:58'),(54,10126,'A','2021-02-02',3,3,'2021-05-26 18:24:57'),(55,10127,'A','2021-02-02',3,3,'2021-05-26 18:29:51'),(56,10128,'A','2021-02-02',3,2,'2021-05-26 18:38:46'),(57,10129,'A','2021-02-02',3,2,'2021-05-26 18:46:17'),(58,10130,'A','2021-02-02',3,2,'2021-05-26 18:51:03'),(59,10131,'A','2021-02-01',3,2,'2021-05-26 19:15:33'),(60,10132,'A','2021-02-02',3,3,'2021-05-26 19:31:46'),(61,10133,'A','2021-02-02',3,2,'2021-05-26 19:34:34'),(62,10134,'A','2021-02-02',3,2,'2021-05-26 20:01:02'),(63,10135,'A','2021-02-02',3,2,'2021-05-26 20:14:15'),(64,10136,'A','2021-02-02',3,3,'2021-05-26 21:32:07'),(65,10137,'A','2021-02-02',3,3,'2021-05-26 21:34:18'),(66,10138,'A','2021-02-02',3,2,'2021-05-27 00:27:44'),(67,10139,'A','2021-02-02',3,2,'2021-05-27 01:05:21'),(68,10140,'A','2021-02-02',3,2,'2021-05-27 03:40:31'),(69,10141,'A','2021-02-02',3,2,'2021-05-27 03:41:53'),(70,10142,'A','2021-03-04',3,2,'2021-05-27 03:42:45'),(71,10143,'A','2021-02-01',3,2,'2021-05-27 03:45:51'),(72,10144,'A','2021-02-02',3,2,'2021-05-27 04:06:07'),(73,10145,'A','2021-02-01',3,2,'2021-05-27 04:07:54'),(74,10146,'A','2021-02-02',3,2,'2021-05-27 04:11:03'),(75,10147,'A','2021-02-02',3,3,'2021-05-27 04:40:06'),(76,10148,'A','2021-02-02',3,2,'2021-05-27 04:44:36'),(77,10149,'A','2021-02-02',3,3,'2021-05-27 04:50:21'),(78,10150,'A','2021-02-02',3,2,'2021-05-27 05:00:24'),(79,10151,'A','2021-02-02',3,1,'2021-05-27 05:03:00'),(80,10152,'A','2021-02-02',3,2,'2021-05-27 05:06:20'),(81,10153,'A','2021-02-02',3,3,'2021-05-27 05:13:42'),(82,10154,'A','2021-02-02',3,2,'2021-05-27 09:51:43'),(83,10155,'A','2021-02-02',3,2,'2021-05-27 11:44:40'),(84,10156,'A','2021-02-02',3,2,'2021-05-27 16:03:12'),(85,10157,'A','2021-02-02',7,2,'2021-05-27 18:36:56'),(86,10158,'A','2021-02-02',7,3,'2021-05-28 20:16:36'),(87,10159,'A','2021-02-01',8,2,'2021-05-30 21:36:39'),(89,10160,'A','2021-01-01',5,2,'2021-05-31 00:55:58'),(90,10161,'A','2021-02-02',8,3,'2021-06-01 22:30:00'),(91,10162,'A','2021-02-02',11,2,'2021-06-01 22:32:18'),(92,10163,'A','2021-06-01',8,2,'2021-06-01 23:18:00'),(93,10164,'A','2021-06-01',8,2,'2021-06-01 23:18:30'),(94,10165,'A','2021-06-01',8,2,'2021-06-01 23:25:43'),(95,10166,'A','2021-06-01',8,4,'2021-06-01 23:30:29'),(96,10167,'A','2021-06-02',8,2,'2021-06-02 00:02:49'),(97,10168,'A','2021-06-02',8,3,'2021-06-02 00:04:43'),(98,10169,'A','2021-06-02',8,3,'2021-06-02 00:16:59'),(99,10170,'A','2021-06-02',5,3,'2021-06-02 00:22:35'),(100,10171,'A','2021-06-02',8,2,'2021-06-02 01:34:10'),(101,10172,'A','2021-06-02',8,2,'2021-06-02 12:10:11'),(102,10173,'A','2021-06-03',8,3,'2021-06-03 00:21:57'),(103,10174,'A','2021-06-03',7,3,'2021-06-03 00:23:38'),(104,10175,'A','2021-06-03',3,3,'2021-06-03 00:31:07'),(105,10176,'A','2021-06-03',3,3,'2021-06-03 00:36:02'),(106,10177,'A','2021-06-03',8,3,'2021-06-03 00:46:52'),(107,10178,'A','2021-06-03',4,3,'2021-06-03 00:48:22'),(108,10179,'A','2021-06-03',5,3,'2021-06-03 01:07:32'),(109,10180,'A','2021-06-03',5,1,'2021-06-03 01:08:56'),(110,10181,'A','2021-06-03',3,3,'2021-06-03 01:11:15'),(111,10182,'A','2021-06-03',8,4,'2021-06-03 01:34:35'),(112,10183,'A','2021-06-03',8,3,'2021-06-03 01:38:45'),(113,10184,'A','2021-06-03',3,3,'2021-06-03 01:41:38'),(114,10185,'A','2021-06-03',3,2,'2021-06-03 01:43:25'),(115,10186,'A','2021-06-03',3,2,'2021-06-03 01:48:25'),(116,10187,'A','2021-06-03',3,3,'2021-06-03 01:52:14'),(117,10188,'A','2021-06-03',3,4,'2021-06-03 01:55:32'),(118,10189,'A','2021-06-03',3,2,'2021-06-03 02:01:46'),(119,10190,'A','2021-06-03',8,2,'2021-06-03 02:18:26'),(120,10191,'A','2021-06-03',8,5,'2021-06-03 02:24:59'),(121,10192,'A','2021-06-03',8,2,'2021-06-03 02:34:11'),(122,10193,'A','2021-06-03',8,3,'2021-06-03 02:36:33'),(123,10194,'A','2021-06-03',8,3,'2021-06-03 02:41:28'),(124,10195,'A','2021-06-03',8,3,'2021-06-03 02:59:32'),(125,10196,'A','2021-06-03',8,2,'2021-06-03 03:07:49'),(126,10197,'A','2021-06-03',8,3,'2021-06-03 03:13:11'),(127,10198,'A','2021-06-03',8,2,'2021-06-03 03:17:09'),(128,10199,'A','2021-06-03',8,3,'2021-06-03 03:24:30'),(129,10200,'A','2021-06-03',8,2,'2021-06-03 03:30:48'),(130,10201,'A','2021-06-03',8,2,'2021-06-03 03:34:27'),(131,10202,'A','2021-06-03',3,2,'2021-06-03 03:36:25'),(132,10203,'A','2021-06-03',3,2,'2021-06-03 03:40:14'),(133,10204,'A','2021-06-03',3,2,'2021-06-03 03:42:30'),(134,10205,'A','2021-06-03',3,2,'2021-06-03 03:45:55'),(135,10206,'A','2021-06-03',3,3,'2021-06-03 03:52:45'),(136,10207,'A','2021-06-03',3,2,'2021-06-03 04:59:33'),(137,10208,'A','2021-06-03',14,2,'2021-06-03 05:03:38'),(138,10209,'A','2021-06-03',16,2,'2021-06-03 05:12:57'),(139,10210,'A','2021-06-03',8,2,'2021-06-03 10:51:36'),(140,10211,'A','2021-06-03',16,2,'2021-06-03 12:25:28');
/*!40000 ALTER TABLE `ventas` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `ventas_detalle`
--

DROP TABLE IF EXISTS `ventas_detalle`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `ventas_detalle` (
  `id_venta_detalle` bigint NOT NULL AUTO_INCREMENT,
  `id_venta` int NOT NULL,
  `id_producto` int NOT NULL,
  `cantidad` varchar(45) DEFAULT NULL,
  `precio_unitario` decimal(8,2) DEFAULT NULL,
  `subtotal` decimal(8,2) DEFAULT NULL,
  PRIMARY KEY (`id_venta_detalle`),
  KEY `id_venta_detalle_venta_detalle_idx` (`id_venta`),
  KEY `id_venta_detalle_venta_detalle_productos_idx` (`id_producto`),
  CONSTRAINT `id_venta_detalle_venta_detalle` FOREIGN KEY (`id_venta`) REFERENCES `ventas` (`id_venta`) ON UPDATE CASCADE,
  CONSTRAINT `id_venta_detalle_venta_detalle_productos` FOREIGN KEY (`id_producto`) REFERENCES `productos` (`id_producto`) ON UPDATE CASCADE
) ENGINE=InnoDB AUTO_INCREMENT=399 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `ventas_detalle`
--

LOCK TABLES `ventas_detalle` WRITE;
/*!40000 ALTER TABLE `ventas_detalle` DISABLE KEYS */;
INSERT INTO `ventas_detalle` VALUES (1,1,1,'20',3.00,NULL),(2,2,3,'40',12.00,NULL),(3,3,2,'30',10.00,NULL),(4,4,4,'20',1.00,NULL),(5,5,5,'50',1.00,NULL),(6,10,2,'3',4.00,NULL),(7,10,3,'4',4.00,NULL),(8,10,4,'5',4.00,NULL),(9,10,2,'3',5.00,NULL),(10,10,2,'3',4.00,NULL),(11,10,4,'3',2.00,NULL),(88,10,3,'3',2.00,NULL),(89,10,1,'1',1.00,NULL),(90,10,3,'3',10.00,NULL),(91,10,2,'3',2.00,NULL),(92,10,3,'2',1.00,NULL),(93,10,2,'2',2.00,NULL),(94,10,2,'3',4.00,NULL),(97,10,3,'2',3.00,NULL),(98,10,3,'4',5.00,NULL),(99,10,1,'1',1.00,NULL),(101,16,2,'2',2.00,NULL),(102,16,2,'3',2.00,NULL),(103,16,2,'2',3.00,NULL),(104,16,2,'3',4.00,NULL),(105,16,3,'4',5.00,NULL),(106,16,5,'5',2.00,NULL),(107,17,1,'2',3.00,NULL),(108,17,3,'3',2.00,NULL),(109,17,3,'4',5.00,NULL),(110,17,2,'1',1.00,NULL),(112,18,3,'2',3.00,NULL),(113,18,3,'3',4.00,NULL),(114,19,3,'2',3.00,NULL),(115,19,3,'2',2.00,NULL),(116,19,3,'2',5.00,NULL),(117,19,4,'5',2.00,NULL),(118,20,1,'2',3.00,NULL),(119,20,3,'2',3.00,NULL),(120,20,4,'5',6.00,NULL),(122,21,2,'2',2.00,NULL),(124,23,4,'4',4.00,NULL),(125,23,4,'5',6.00,NULL),(126,23,3,'4',5.00,NULL),(127,23,2,'2',2.00,NULL),(128,23,2,'2',2.00,NULL),(129,23,3,'2',1.00,NULL),(130,24,1,'2',3.00,NULL),(131,24,2,'3',4.00,NULL),(132,24,2,'3',4.00,NULL),(133,29,2,'2',2.00,NULL),(134,34,3,'3',2.00,NULL),(135,34,4,'5',3.00,NULL),(137,35,2,'3',4.00,NULL),(138,35,3,'2',3.00,NULL),(139,35,2,'3',4.00,NULL),(140,36,2,'2',2.00,NULL),(141,36,3,'2',2.00,NULL),(142,36,2,'3',2.00,NULL),(143,37,2,'2',2.00,NULL),(144,37,3,'4',5.00,NULL),(145,37,3,'4',5.00,NULL),(146,38,3,'3',3.00,NULL),(147,38,2,'3',4.00,NULL),(148,39,3,'3',2.00,NULL),(149,39,2,'3',2.00,NULL),(150,39,2,'2',2.00,NULL),(152,41,2,'3',5.00,NULL),(153,41,2,'3',5.00,NULL),(154,41,2,'3',3.00,NULL),(155,42,2,'3',5.00,NULL),(156,42,3,'4',6.00,NULL),(157,43,2,'2',4.00,NULL),(158,43,3,'4',6.00,NULL),(159,43,3,'4',6.00,NULL),(160,43,2,'3',5.00,NULL),(161,43,2,'3',2.00,NULL),(162,43,2,'10',3.00,NULL),(163,44,2,'2',2.00,NULL),(164,44,3,'2',2.00,NULL),(165,44,2,'5',5.00,NULL),(166,44,2,'3',4.00,NULL),(167,45,2,'2',2.00,NULL),(168,45,2,'2',2.00,NULL),(169,45,1,'4',2.00,NULL),(170,46,2,'10',10.00,NULL),(171,46,1,'5',5.00,NULL),(172,46,2,'5',10.00,NULL),(173,47,2,'10',5.00,NULL),(174,47,2,'5',5.00,NULL),(175,47,2,'5',5.00,NULL),(176,48,2,'10',5.00,NULL),(177,49,2,'3',10.00,NULL),(178,49,3,'2',10.00,NULL),(179,49,2,'1',2.00,NULL),(180,50,2,'2',2.00,NULL),(181,50,3,'4',5.00,NULL),(182,50,1,'10',3.00,NULL),(183,51,2,'10',2.00,NULL),(184,51,2,'5',2.00,NULL),(185,51,3,'3',3.00,NULL),(186,52,2,'2',2.00,NULL),(187,52,1,'3',10.00,NULL),(188,52,3,'2',3.00,NULL),(189,53,2,'2',2.00,NULL),(190,53,1,'3',3.00,NULL),(191,53,3,'2',4.00,NULL),(192,54,2,'2',2.00,NULL),(193,54,4,'3',2.00,NULL),(194,54,2,'4',2.00,NULL),(195,55,4,'5',4.00,NULL),(196,55,2,'3',5.00,NULL),(197,55,1,'3',2.00,NULL),(198,56,2,'2',2.00,NULL),(199,56,3,'4',5.00,NULL),(200,56,3,'2',1.00,NULL),(201,57,3,'2',3.00,NULL),(202,57,4,'3',3.00,NULL),(203,57,4,'2',2.00,NULL),(204,58,2,'3',2.00,NULL),(205,58,3,'3',2.00,NULL),(206,58,1,'2',4.00,NULL),(207,59,2,'2',2.00,NULL),(208,59,1,'10',2.00,NULL),(209,59,3,'4',5.00,NULL),(210,60,5,'6',5.00,NULL),(211,60,2,'2',3.00,NULL),(212,60,1,'3',7.00,NULL),(213,61,2,'2',3.00,NULL),(214,61,3,'3',5.00,NULL),(215,61,1,'4',2.00,NULL),(216,62,2,'2',3.00,NULL),(217,62,3,'1',2.00,NULL),(218,63,2,'2',3.00,NULL),(219,63,1,'3',4.00,NULL),(220,65,2,'3',2.00,NULL),(221,65,3,'4',10.00,NULL),(222,65,1,'3',3.00,NULL),(223,66,2,'2',2.00,NULL),(224,66,3,'4',5.00,NULL),(225,67,2,'2',2.00,NULL),(226,67,2,'3',2.00,NULL),(227,67,1,'10',2.00,NULL),(230,70,4,'5',4.00,NULL),(231,70,2,'3',2.00,NULL),(232,71,2,'2',2.00,NULL),(233,71,2,'3',2.00,NULL),(234,72,2,'2',2.00,NULL),(235,72,2,'3',4.00,NULL),(236,73,5,'5',5.00,NULL),(237,73,2,'6',8.00,NULL),(238,74,2,'2',2.00,NULL),(239,74,3,'4',5.00,NULL),(240,75,2,'3',4.00,12.00),(241,75,3,'4',2.00,8.00),(242,75,4,'2',3.00,6.00),(243,76,2,'3',2.00,6.00),(244,76,2,'4',2.00,8.00),(245,76,3,'2',5.00,10.00),(246,77,2,'1',3.00,3.00),(247,77,3,'4',5.00,20.00),(248,77,2,'2',4.00,8.00),(249,78,2,'3',4.00,12.00),(250,78,3,'4',5.00,20.00),(251,79,2,'3',4.00,12.00),(252,79,3,'4',5.00,20.00),(253,79,2,'3',4.00,12.00),(254,80,2,'3',4.00,12.00),(255,81,3,'4',2.00,8.00),(256,81,3,'4',2.00,8.00),(257,81,2,'2',4.00,8.00),(258,82,2,'3',4.00,12.00),(259,82,3,'4',3.00,12.00),(260,82,1,'1',3.00,3.00),(261,83,2,'3',3.00,9.00),(262,83,3,'4',2.00,8.00),(263,83,1,'1',1.00,1.00),(264,84,3,'4',3.00,12.00),(265,84,3,'4',5.00,20.00),(266,84,2,'5',2.00,10.00),(267,85,2,'5',2.00,10.00),(268,85,3,'4',6.00,24.00),(269,85,1,'3',7.00,21.00),(270,86,2,'2',10.00,20.00),(271,86,3,'4',5.00,20.00),(272,86,1,'10',2.00,20.00),(273,86,4,'2',6.00,12.00),(274,86,3,'2',4.00,8.00),(275,86,5,'3',3.00,9.00),(276,86,1,'25',2.00,50.00),(277,87,3,'4',3.00,12.00),(278,87,3,'2',4.00,8.00),(279,87,4,'2',4.00,8.00),(280,89,2,'20',2.00,40.00),(281,89,2,'10',2.00,20.00),(282,89,3,'50',4.00,200.00),(283,89,1,'18',2.00,36.00),(284,90,2,'10',4.00,40.00),(285,90,3,'3',3.50,10.50),(286,90,1,'10',2.50,25.00),(287,91,2,'3',3.50,10.50),(288,91,3,'2',2.50,5.00),(289,91,1,'7',2.50,17.50),(290,93,2,'20',2.00,40.00),(291,97,3,'4',5.00,20.00),(292,97,4,'5',2.50,12.50),(293,98,3,'2',5.00,10.00),(294,99,4,'3',4.00,12.00),(295,100,2,'10',3.50,35.00),(296,101,2,'3',2.50,7.50),(297,101,3,'1',5.00,5.00),(298,101,4,'1',3.75,3.75),(299,102,2,'3',3.00,9.00),(300,103,2,'3',2.00,6.00),(301,104,2,'3',4.00,12.00),(302,104,2,'3',2.00,6.00),(303,104,1,'4',2.00,8.00),(304,105,2,'3',2.00,6.00),(305,105,1,'3',2.50,7.50),(306,106,2,'2',2.50,5.00),(307,106,2,'1',3.00,3.00),(308,106,4,'5',1.00,5.00),(309,107,2,'10',2.50,25.00),(310,107,1,'7',2.50,17.50),(311,107,5,'2',4.50,9.00),(312,108,2,'3',2.50,7.50),(313,108,3,'1',2.00,2.00),(314,108,1,'5',3.00,15.00),(315,109,4,'2',3.00,6.00),(316,109,2,'5',3.50,17.50),(317,109,1,'2',2.50,5.00),(318,110,2,'3',4.00,12.00),(319,110,3,'3',5.00,15.00),(320,111,3,'4',4.00,16.00),(321,111,1,'3',2.00,6.00),(322,111,3,'2',1.00,2.00),(323,112,2,'3',2.00,6.00),(324,112,4,'4',2.50,10.00),(325,112,1,'2',1.00,2.00),(326,113,2,'2',2.50,5.00),(327,113,1,'4',10.00,40.00),(328,113,3,'1',3.50,3.50),(329,114,2,'3',2.50,7.50),(330,114,4,'2',3.50,7.00),(331,114,1,'3',2.50,7.50),(332,115,2,'3',3.00,9.00),(333,115,1,'2',3.00,6.00),(334,115,3,'2',2.50,5.00),(335,115,5,'4',3.50,14.00),(336,116,2,'3',2.00,6.00),(337,116,1,'4',5.00,20.00),(338,116,2,'3',4.00,12.00),(339,117,2,'1',2.00,2.00),(340,117,3,'3',4.00,12.00),(341,117,2,'5',2.00,10.00),(342,118,2,'3',2.00,6.00),(343,118,3,'4',3.50,14.00),(344,118,1,'2',2.50,5.00),(345,119,3,'2',2.00,4.00),(346,119,2,'5',5.00,25.00),(347,119,1,'2',2.50,5.00),(348,120,4,'5',6.00,30.00),(349,121,2,'3',2.00,6.00),(350,122,2,'3',2.00,6.00),(351,123,3,'2',2.00,4.00),(352,124,4,'4',4.00,16.00),(353,124,2,'2',5.00,10.00),(354,124,1,'2',4.00,8.00),(355,125,3,'3',4.00,12.00),(356,125,2,'3',5.00,15.00),(357,125,1,'5',2.00,10.00),(358,126,2,'3',4.00,12.00),(359,126,3,'4',5.00,20.00),(360,126,1,'2',2.50,5.00),(361,127,2,'3',3.00,9.00),(362,127,1,'5',4.00,20.00),(363,127,4,'1',2.00,2.00),(364,128,2,'3',2.00,6.00),(365,128,3,'4',5.00,20.00),(366,128,1,'3',4.00,12.00),(367,129,3,'2',2.00,4.00),(368,129,4,'4',5.00,20.00),(369,129,1,'2',4.00,8.00),(370,130,2,'2',2.00,4.00),(371,130,3,'4',1.00,4.00),(372,130,4,'2',4.00,8.00),(373,131,2,'2',2.00,4.00),(374,131,3,'4',3.00,12.00),(375,131,4,'3',5.00,15.00),(376,132,2,'3',2.00,6.00),(377,132,3,'4',1.00,4.00),(378,132,3,'2',1.00,2.00),(379,132,4,'2',3.00,6.00),(380,133,2,'3',5.00,15.00),(381,133,1,'4',3.50,14.00),(382,133,3,'5',17.00,85.00),(383,134,2,'4',3.00,12.00),(384,134,3,'5',17.00,85.00),(385,134,1,'3',2.50,7.50),(386,135,3,'2',2.00,4.00),(387,135,4,'1',5.00,5.00),(388,135,2,'10',5.00,50.00),(389,136,3,'2',2.00,4.00),(390,137,3,'4',2.00,8.00),(391,138,5,'3',2.00,6.00),(392,138,2,'4',5.00,20.00),(393,139,3,'2',2.00,4.00),(394,139,3,'4',2.00,8.00),(395,139,2,'5',3.50,17.50),(396,140,2,'3',1.00,3.00),(397,140,3,'4',5.00,20.00),(398,140,1,'10',2.50,25.00);
/*!40000 ALTER TABLE `ventas_detalle` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2021-06-03 12:33:04
