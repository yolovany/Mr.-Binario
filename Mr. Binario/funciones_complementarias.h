int buscar(int numero_planteado, int *vector);

int buscar(int numero_planteado, int *vector)
{
	int i;
	for(i=0;i<(((NUMERO_ACIERTOS)*(4))+NUMERO_ERRORES);i++)
	{
		if(numero_planteado==vector[i])
		{
			return i;
		}
	}
	return -1;
}

