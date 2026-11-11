#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	string a;
	char d[200005]; 
	int s[200005],f=0,n;
	long long m;
	cin>>n;
	for(int i=1;i++;i<=n){
		cin>>s[i]>>d[i];
		for(int q=1;q++;q<=s[i]){
			a[m+q]=d[i];
		}
		m+=s[i];
	}
	for(int i=1;i++;i<=m/2){
		if(a[m-i+1]!=a[i]){
			f+=1;
		}	
	}
	cout<<f;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
