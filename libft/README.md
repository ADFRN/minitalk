# libft

![Result](./result.png)

Une implémentation complète d'une librairie de fonctions C standard réutilisables.

## 📋 Description

**libft** est une librairie C qui réimplémente les fonctions essentielles de la libc et ajoute des fonctionnalités supplémentaires. Elle est structurée en trois parties principales :
- Les fonctions standards de la libc
- Les fonctions supplémentaires utiles
- La gestion de listes chaînées

## 🚀 Installation

```bash
make        # Compile la librairie
make clean  # Supprime les fichiers objets
make fclean # Supprime les fichiers objets et la librairie
make re     # Recompile complètement
```

## 📚 Contenu

### Part 1 - Fonctions Libc

| Fonction | Description |
|----------|-------------|
| `ft_isalpha` | Vérifie si le caractère est alphabétique |
| `ft_isdigit` | Vérifie si le caractère est un chiffre |
| `ft_isalnum` | Vérifie si le caractère est alphanumérique |
| `ft_isascii` | Vérifie si le caractère est ASCII |
| `ft_isprint` | Vérifie si le caractère est imprimable |
| `ft_strlen` | Retourne la longueur d'une chaîne |
| `ft_memset` | Remplit une zone mémoire avec une valeur |
| `ft_bzero` | Remet une zone mémoire à zéro |
| `ft_memcpy` | Copie une zone mémoire |
| `ft_memmove` | Copie une zone mémoire (chevauchements possibles) |
| `ft_memchr` | Cherche un caractère dans une zone mémoire |
| `ft_memcmp` | Compare deux zones mémoire |
| `ft_strlcpy` | Copie une chaîne de manière sécurisée |
| `ft_strlcat` | Concatène deux chaînes de manière sécurisée |
| `ft_strchr` | Cherche un caractère dans une chaîne |
| `ft_strrchr` | Cherche la dernière occurrence d'un caractère |
| `ft_strncmp` | Compare deux chaînes (nombre limité de caractères) |
| `ft_strnstr` | Cherche une sous-chaîne |
| `ft_atoi` | Convertit une chaîne en entier |
| `ft_tolower` | Convertit un caractère en minuscule |
| `ft_toupper` | Convertit un caractère en majuscule |

### Part 2 - Fonctions Supplémentaires

| Fonction | Description |
|----------|-------------|
| `ft_calloc` | Alloue et initialise une zone mémoire |
| `ft_strdup` | Duplique une chaîne |
| `ft_substr` | Extrait une sous-chaîne |
| `ft_strjoin` | Concatène deux chaînes |
| `ft_strtrim` | Supprime les caractères spécifiés aux extrémités |
| `ft_split` | Divise une chaîne selon un séparateur |
| `ft_itoa` | Convertit un entier en chaîne |
| `ft_strmapi` | Applique une fonction à chaque caractère |
| `ft_striteri` | Applique une fonction à chaque caractère avec index |
| `ft_putchar_fd` | Écrit un caractère dans un descripteur de fichier |
| `ft_putstr_fd` | Écrit une chaîne dans un descripteur de fichier |
| `ft_putendl_fd` | Écrit une chaîne suivie d'un saut de ligne |
| `ft_putnbr_fd` | Écrit un nombre dans un descripteur de fichier |
| `ft_printf` | Fonction printf personnalisée |

### Part 3 - Gestion de Listes Chaînées

| Fonction | Description |
|----------|-------------|
| `ft_lstnew` | Crée un nouveau nœud de liste |
| `ft_lstadd_front` | Ajoute un nœud au début |
| `ft_lstadd_back` | Ajoute un nœud à la fin |
| `ft_lstsize` | Retourne la taille de la liste |
| `ft_lstlast` | Retourne le dernier nœud |
| `ft_lstdelone` | Supprime un nœud |
| `ft_lstclear` | Supprime toute la liste |
| `ft_lstiter` | Applique une fonction à chaque nœud |
| `ft_lstmap` | Crée une nouvelle liste en appliquant une fonction |

