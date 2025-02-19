float sum_mul()
{
	int flag = 0;
	float sum = 0.00000;
	for(float i = 0.0000; i < 100.0000; i += 0.1)
	{
		if(flag == 0)
			sum += i;
		else
			sum *= i;
	}
	return sum;
}
