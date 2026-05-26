[Service]
Type=simple
User=root
WorkingDirectory=/root/llama.cpp/build/bin
ExecStart=/root/llama.cpp/build/bin/llama-server -m /root/models/Qwen3.6-35B-A3B-Q4_K_M.gguf --mmproj "/root/models/mmproj-F16.gguf" --host 0.0.0.0 --port 8080 -ngl 16 -c 262144 -t 10 --jinja -b 2048 -ub 512 --temp 0.6 --top-p 0.85 --top-k 30 --parallel 2 --log-disable --cache-type-k q8_0 --cache-type-v q8_0 --repeat-penalty 1.15 --dry-multiplier 1.2 --dry-base 0.0

Restart=always
RestartSec=10
StartLimitIntervalSec=60
StartLimitBurst=3

[Install]
WantedBy=multi-user.target
