#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<stack>
using namespace std;
int a[500005];
long long t[300005],t1[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		printf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		memset(t,0,sizeof t);
		stack <int> s;
		for(int j=i;j<=n;j++){
			if((t[a[j]]+1)>=2){
				while(!s.empty() && s.top()!=a[j]){
					t[s.top()]--;
					s.pop();
				}
			}
			else{
				s.push(a[j]);
				t[a[j]]++;
			}
			
		}
		for(int i=1;i<=m;i++){
			t1[i]+=t[i];
		}
	}
	for(int i=1;i<=m;i++){
		if(i==m){
			cout<<t1[i];
		}
		else{
			cout<<t1[i]<<" ";
		}
	}
	return 0;
} 
