#include "hash_tables.h"
/**
 * hash_table_set - function that adds an element to the hash table.
 * @ht: The hash table you want to add or update the key/value to.
 * @key: The key
 * @value: The value associated with the key.
 * Return: 1 if it succeeded, 0 otherwise
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index;
	const char *value_cp, *key_cp;
	hash_node_t *aux = NULL;
	hash_node_t *node = NULL;

	node = malloc(sizeof(hash_node_t));
	if (node == NULL)
	{
		return (0);
	}
	if (ht == NULL || key == NULL || value == NULL || strcmp(key, "") == 0)
	{
		return (0);
	}
	/* get the index */
	index = key_index((const unsigned char *)key, ht->size);
	value_cp = strdup(value);
	key_cp = strdup(key);
	node->key = (char *)key_cp;
	node->value = (char *)value_cp;
	node->next = NULL;
	if (ht->array[index] == NULL)
	{
		ht->array[index] = node;
	}
	else
	{
		aux = ht->array[index];
		node->next = aux;
		ht->array[index] = node;
	}
	printf("%lu : %s : %s\n", index, ht->array[index]->key, ht->array[index]->value);
	return (1);
}
