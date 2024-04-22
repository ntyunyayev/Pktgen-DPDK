package.path = package.path .. ";/etinfo/users2/tyunyayev/Workspace/Pktgen-DPDK/?.lua"

require("Pktgen")

prints("portStats", pktgen.portStats('all', 'port'));

