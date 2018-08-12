#include <stdio.h>
// #include <conio.h>

#define MAX 100

#define YES 1
#define NO 0

int InFile(int *a, int *N);
int UniversalSink(const int *a, int N);
int main()
{
    int a[MAX][MAX],N,m;
    InFile( (int*) a, &N);
    m=UniversalSink( (const int *) a, N);
    if (m == -1) {
        printf("There is no universal sink in this graph\n");
    } else {
        printf("Universal sink at column number %d \n", m+1);
    }
    // getch();
    getchar();
    return 0;
}

int InFile(int *a, int *N)
{
    FILE *f;
    int i,j,q;
    f = fopen("UNISINK.txt","r");
    fscanf(f,"%d",N);
    for (i=0; i<(*N) ; i++ )
        for (j=0; j<(*N); j++ )
            fscanf(f,"%d",a + i*MAX +j );
    fclose(f);
    return 0;
}

int UniversalSink(const int *a, int N)
{
    int i,j,i1,j1,q;
    i=0;


    i=0;
    q=YES;
    j=-1;
    do
    {
	j++;
	if (j==N)
	    break;

	while ( (*(a+i*MAX+j)) ==0 )
	{
	    j++;
	    if (j==N)
	    {

		break;
	    }
	}
	if (j==N)
	    break;
	q= YES;

	for (; i<j; i++)
	    if ( (*(a+i*MAX+j)) ==0 )
	    {
	       i=j,j=i-1;
	       q= NO;
	       break;
	    }
	if (q==NO)
	    continue;
	q=YES;

	/*
	for (i=0; i<=j; i++ )
	    if (a[j][i] ==1 )
	    {
		i=j;
		q=NO;
		ok=NO;
		trai = NO;
		break;

	    }
	if (q==NO)
	    continue;
	*/
	q=YES;

	for (i1= j+1; i1<N; i1++)
	    if ((*(a + i1*MAX +j)) ==0 )
	    {
		i=i1, j=i-1;
		q=NO;
		break;

	    }
	if (q==NO)
	    continue;
    }
    while (j<N);

    {
	i1=i;
	for (j1=0; j1<N;j1++)
	    if ( (*(a + i1*MAX +j1 ))  ==1 )
		return -1;
	j1=i;
	for (i1=0; i1<N;i1++)
	{
	    if (i1==j1)
		continue;
	    if ( (*(a + i1*MAX +j1))==0)
		return -1;
	}
	return i;

    }

}
