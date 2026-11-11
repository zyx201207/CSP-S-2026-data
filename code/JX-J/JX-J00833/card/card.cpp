#include<bits/stdc++.h>
using namespace std;

int n,m,a[500010],s[300010],ers=0;

void card(int i){
	int k[500010];
	memset(k,0,sizeof(k));
	for(int j=i;j<n;j++){
		for(int h=0;h<n;h++){
			if(k[h]==0&&ers!=1){
				k[h]=a[j];
				break;
			}
			else if(a[j]==k[h]){
				ers=1;
				continue;
			}
			if(ers==1) k[h]=0;
		}
		ers=0;
	}
	for(int j=0;j<n;j++) s[k[j]]+=1;
}

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	memset(a,0,sizeof(a));
	memset(s,0,sizeof(s));
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		card(i);
	}
	for(int i=1;i<=m;i++) cout<<s[i]<<' ';
	
	return 0;
}
