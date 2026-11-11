#include<bits/stdc++.h>
using namespace std;
long long a[200003];
long long p[50],q[50];
long long fp(int a,int x){
	if(x==0)return 1;
	long long t=fp(a,x/2);
	if(x%2==0)return t*t;
	return t*t*a;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<=31;i++){
		q[i]=fp(2,i);
	}
	queue<int> qq;
	for(int i=1;i<=n;i++){
		qq.push(i);
		cin>>a[i];
	}
	long long ans=0,k=31;
	while(1){
		int l=qq.size();
		memset(p,0,sizeof(p));
		for(int i=0;i<l;i++){
			int t=qq.front();
			qq.pop();
			qq.push(t);
			int j=0;
			while(q[j]<=a[t]){
				if((q[j]&a[t])==q[j])p[j]++;
				j++;
			}
		}
		int tk=k;
		for(int i=k-1;i>=0;i--){
//			cout<<p[i]<<' ';
			if(p[i]>=m){
				k=i;
				break;
			}
		}
//		cout<<endl;
		if(k==tk){
			cout<<ans;
			return 0;
		}
		ans+=q[k];
		for(int i=0;i<l;i++){
			int t=qq.front();
			qq.pop();
			if((q[k]&a[t])==q[k])qq.push(t);
		}
	}
	return 0;
} 
