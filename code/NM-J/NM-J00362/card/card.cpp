#include<bits/stdc++.h>
using namespace std;
int a[500005];
int n,m,mx=-114514;

int pai(int q,int k){stack<int> st;
	int ha[500005];
	for(int u=q;u<=n;u++){
		ha[u]++;}
		for(int u=q;u<=n;u++){
			e:
			if(ha[u]<=1){
			st.push(a[u]);
			ha[u]++;}
			else{
			while(!st.empty()||st.top()!=a[u]){st.pop();}
			ha[u]--;
			goto e;
		}}
		if(ha[k]!=0)
		return q;
		return 0;
}
int main(){
freopen("card.in","r",stdin);
freopen("card.out","w",stdout);
cin>>n>>m;
for(int i=1;i<=n;i++){

    cin>>a[i];
}
for(int i=1;i<=n;i++){
	mx=max(0,pai(i,i));
	if(mx==0)
	continue;
	cout<<mx<<" ";
}


return 0;
}
