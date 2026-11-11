#include<bits/stdc++.h>
using namespace std;
int a[500001];
int x[500001];
int c[300001];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
	}
	if(m == 2){
		int a1 = 0,a2 = 0;
		for(int i = 1;i <= n;i++)
		{
			if(a[i] == 1){
				a1++;
			}else if(a[i]==2){
				a2++;
			}
		}
		if(a[n] == 1){
			cout<<n<<" "<<a2<<endl;
			return 0; 
		}else if(a[n] == 2){
			cout<<a1<<" "<<n<<endl;
			return 0;
		}
	}else if(m==1){
		cout<<n<<endl;
		return 0;
	}
	for(int i = 1;i <= n;i++){
		int tail = -1;
		for(int j = i;j <= n;j++){
			for(int s = 0;s <= tail;s++){
				if(x[s] == a[j]){
					tail=s-1;
					break;
				}
			}
			x[tail+1] = a[j];
			tail++;
		}
		for(int j = 0;j <= tail;j++){
			c[x[j]]++;
		}
	}
	for(int i = 1;i <= m;i++){
		cout<<c[i]<<" ";
	}
	return 0;
} 
