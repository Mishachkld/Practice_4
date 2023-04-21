# Задача №4
# Умный дом

В системе «Умный дом» используется управляющий компьютер, который взаимодействует с различными приборами.

Приборы подразделяются на несколько категорий:
##	Счетчики электрической энергии
      a.	Меркурий 230 (Merkuri 230)
      b.	Нева МТ314 (Nev МТ314)
      c.	Энергомера CE308 (Energomera CE308)
##	Блоки ввода дискретных сигналов:
      a.	Reallab NL-16HV
      b.	Приборэлектро PRE-16 (PriborElectro PRE-16)
      c.	Энергосервис ЭНМВ-1-24 (Energoservice ENMV-1-24)
##	Блоки управления отоплением
      a.	Ouman S203
      b.	Овен ТРМ232 (Oven TPM232)

Получить данные от каждого прибора можно через метод

`void poll() {
std::cout << “Device name” << std::endl;
// Некоторая реализация получения данных, которую вам делать
// не нужно.
}`

Для реализации конкретного проекта умного дома проектировщики могут выбрать, как правило, по одному прибору каждого типа. Тем не менее, программа должна поддерживать их все.
