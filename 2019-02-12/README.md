# Final Informática 1 - UTN FRBA - 2019 02 12

## Consigna
Antes que nada, adjunto una foto del final porque me tomé la libertad de rescribir un poco la consiga para que, a mi criterio, se entienda mejor.

Si bien parte de la evaluación es poder interpretar la consigna y planificar su resolución de forma ordenada, siento que el texto es por momentos confuso.

[Consigna](consigna.md)

## Resolución

### Pruebas

Para enviar una señal **SIGUSR1** mediante consola:
```bash
kill -SIGUSR1 [process id de la aplicación]
```

### Links utiles

- [Manejo de Señales en C](https://www.geeksforgeeks.org/signals-c-language/)
- [man waitpid](https://linux.die.net/man/2/waitpid)
- [fork](https://www.geeksforgeeks.org/fork-system-call/)
- [stack vs heap](http://net-informations.com/faq/net/stack-heap.htm)

## TODO

- [ ] Diagrama de flujo?
- [x] Manejo de Señales
- [x] Manejo de Procesos
- [ ] Comunicación entre Procesos
  - [ ] via socket
  - [ ] via named-fifo
- [ ] Documentar todo
