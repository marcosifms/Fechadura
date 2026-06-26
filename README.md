# Detecção de Árvores com Faster R-CNN

Projeto final da disciplina de Visão Computacional — detecção de árvores em imagens urbanas utilizando Faster R-CNN com Transfer Learning em PyTorch.

---

## Pré-requisitos

Antes de executar o código, instale as dependências necessárias:

```bash
pip install torch torchvision pycocotools matplotlib pillow
```

---

## Download e organização do dataset

Baixe o dataset pelo link abaixo e descompacte o arquivo `.zip` em uma pasta de sua escolha:

🔗 [Download do dataset (Google Drive)](https://drive.google.com/file/d/1KJNZixm6ou9EYo_YrudKBdDt-D_Sy3kf/view?usp=sharing)

Após descompactar, a estrutura de pastas deve ficar assim:

```
annotated_dataset/
├── images/
│   ├── imagem1.png
│   └── imagem2.png
└── coco_annotations.json
```

---

## Configurar os caminhos no código

Abra o arquivo `tree_detection.py` e localize as **linhas 50 e 51**. Altere os caminhos para apontar para onde você salvou o dataset:

```python
IMG_DIR         = "annotated_dataset/images"
ANNOTATION_FILE = "annotated_dataset/coco_annotations.json"
```

---

## Executar

```bash
python tree_detection.py
```

Ao iniciar, o programa perguntará qual experimento deseja rodar:

```
Qual experimento deseja rodar? (E1, E2 ou E3) [ENTER para E1]:
```

| Experimento | Backbone | Data Augmentation | Épocas | LR |
|---|---|---|---|---|
| E1 (Baseline) | ResNet-50 | Não | 30 | 0,005 |
| E2 | ResNet-101 | Não | 30 | 0,005 |
| E3 | ResNet-50 | Sim | 50 | 0,001 |

Pressione **ENTER** para rodar o E1 (baseline) sem digitar nada.

---

## Resultados

Após a execução, os arquivos gerados são salvos automaticamente na pasta `results/`:

| Arquivo | Descrição |
|---|---|
| `faster_rcnn_e1.pth` | Pesos do modelo treinado |
| `curva_loss_e1.png` | Gráfico de loss de treino e validação |
| `predicoes_e1.png` | Exemplos visuais de detecções |

> O sufixo `_e1`, `_e2` ou `_e3` varia conforme o experimento executado.
