#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	long long a,n,k,m;
	cin>>a>>m;
	cin>>n>>k;
	long long b[n],c[n];
	for(int i=0;i<n;i++){
		cin>>b[i]>>c[i];
	}
	sort(b,b+n);
	sort(c,c+n);
	int i=0;
	while(b[i]==b[1]){
		i++;
	}
	int j=0;
	while(c[j]==c[1]){
		j++;
	}
	for(int i=0;i<m/2;i++){
		cout<<b[i]-1<<"/n";
	}
	for(int i=m/2;i<m;i++){
		cout<<c[j]-1<<"\n";
	}
	return 0;
}
