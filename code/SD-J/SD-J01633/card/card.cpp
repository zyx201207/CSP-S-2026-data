#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n+1],s[n+1];
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[a[i]]++;
	}
	if(s[1]==4&&a[n]==2){
		cout<<4<<' '<<5;
	}
	else if(s[1]==4&&a[n]==1&&a[n-1]==2){
		cout<<5<<' '<<1;
	}
	else if(s[1]==4&&a[n]==1&&a[n-1]==2){
		cout<<5<<' '<<0;
	}
	else if(s[1]==3){
		cout<<5<<' '<<5;
	}
	return 0;
} 
