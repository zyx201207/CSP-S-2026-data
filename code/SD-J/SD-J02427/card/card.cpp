#include<bits/stdc++.h>
using namespace std;
int b[10000000];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[n],c[m],r=0;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
	}
	for(int i=1;i<=m;i++){
		c[i]=0;
	}
	for(int i=1;i<=n;i++){
	stack<int> s;
	for(int j=i+1;j<=n;j++){
		if(b[a[j]]==0){
		s.push(a[j]);
		b[a[j]]=1;
	}
	else{
        while(a[j]!=s.top()){
        	s.pop();
	}
	s.pop();
	s.push(a[j]); 
	}
	}
	while(!s.empty()){
		c[s.top()]++;
		s.pop();
	}
}
for(int i=1;i<=n;i++){
	cout<<c[i];
}
}

