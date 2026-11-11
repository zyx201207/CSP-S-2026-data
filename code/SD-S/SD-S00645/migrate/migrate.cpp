#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("migrate.in","r",stdin);
	int c,t,n,d,x[n],i=0;
	scanf("%d %d",&c,&t);
	switch (i<t){
		i++;
		scanf("%d %d/n",&n,&d);
		cin>>x[n];
		int h;
		if((n-1)%2==0){
			h=0;
			printf("%d",h);
		}
		else{
		    h=n-3;
		    printf("%d",h);
		}
	}
	freopen("migrate.out","w",stdout);

	return 0;
}

