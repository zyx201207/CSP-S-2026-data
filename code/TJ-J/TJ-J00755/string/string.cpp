#include<bits/stdc++.h>//string
using namespace std;
long long n,a[200005],ans;
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}

	long long i=1,j=n;
	while(i<=j){
		if(c[i]==c[j]){
			if(a[i]==a[j]){
				i++;j--;
				continue;
			}
			else {
				long long p=a[i],q=a[j];
				if(p>q){
					a[i]-=q;
					a[j]=0;
					j--;
				}
				else{
					a[j]-=p;
					a[i]=0;
					i++;
				}
			}
		}
		else{
			if(a[i]==a[j]){
				ans+=a[i];
				a[i]=0;
				a[j]=0;
				i++;j--;
			}
			else {
				long long x=a[i],y=a[j];
				ans+=min(x,y);
				if(x>y){
					a[i]-=y;
					a[j]=0;
					j--;
				}
				else{
					a[j]-=x;
					a[i]=0;
					i++;
				}
			}
		}
	}
	cout<<ans;
	return 0;
} 
/*
6
1 f
3 a
6 b
4 c
2 a
2 e

3
2 a
2 b
1 c

6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b


*/
