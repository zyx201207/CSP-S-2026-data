#include<bits/stdc++.h>
using namespace std;
string s1[500005];
int n,m,a[500005],f=0;
struct node{
	int ai,pos;
}b[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=2;i<=n;i++){
		if(a[i]>a[i-1])	continue;
		f=1; 
	}
	if(f==0){
		for(int i=1;i<=m;i++){
			cout<<1<<" ";
		}
		return 0;
	}
	for(int u=1;u<=m;u++){
		
		long long position=0;
		char s[500005];
		long long ans=0; 
		for(int i=u;i<=n;i++){
			if(b[a[i]].ai==0){
				b[a[i]].ai++;
				b[a[i]].pos=i;
			}else if(b[a[i]].ai){
				position=b[a[i]].pos;
				for(int j=position;j<i;j++){
					b[a[j]].ai--;
				}
			}
			s[position++]=a[i]+'0';	
		}
		for(int i=1;i<position;i++){
			cout<<s[i]<<" ";
		}
		cout<<'\n';
		for(int i=1;i<position;i++){
			s1[u]+=s[i];
		}
	}
	for(int i=1;i<=m;i++){
		cout<<s1[i]<<" ";
	}
	return 0;
}
