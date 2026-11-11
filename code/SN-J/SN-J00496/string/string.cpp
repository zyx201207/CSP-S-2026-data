#include<bits/stdc++.h>
using namespace std;
long long a,w=0,ans;
char q[200010],e;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>e;		
		for(int j=1;j<=a;j++) q[w+j]=e;
		w+=a;
	}
	cout<<w<<endl;
	for(int i=1;i<=w/2;i++)
	{
		if(q[i]!=q[w-i+1]) ans++;
		cout<<q[i]<<" "<<q[w-i+1]<<endl;
	}
	cout<<ans;
	return 0;
}
