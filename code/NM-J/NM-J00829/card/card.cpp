#include <iostream>

using namespace std;

int main()
{
   freopen("card.in","r",stdin);
   freopen("card.out","w",stdout);
	int n,m,a,b;
	cin << n << m;
	for (int i = 0 ;i <= n+1;i++){
		n +=m;
	} for(int j = 0;j <= m+1;j++)
	if (n == m){
		n -=m;
	}else if(n !=m){
		n +=m;
		
	}
	cout << n,m<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
