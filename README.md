# GasFinder

GasFinder é um projeto desenvolvido para a disciplina de Objetos Inteligentes Conectados do curso de Sistemas de Informação da Universidade Presbiteriana Mackenzie, tratando-se de um dispositivo com o objetivo de realizar a detecção da concentração de gáses inflamáveis em um ambiente. É constituído por um sensor MQ2, capaz de detectar GLP, fumaça, álcool, propano, hidrogênio, metano e monóxido de carbono, um buzzer que emite um alerta sonoro caso seja detectado a presença de algum desses gases no ambiente, e um módulo nodeMCU responsável por gerenciar este sensor e atuador, e enviar alertas por WhatsApp via broker MQTT para notificar o registro dessa detecção, informando a gravidade do possível vazamento de gás e a concentração deste no ambiente.
