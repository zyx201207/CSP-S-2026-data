#include<bits/stdc++.h>
using namespace std;
long long q,e,n,a[100002];
char c[100001];
string w;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		q=q+a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++){
			w=w+c[i];
    }
	}
	if(q%2==0){
		q=q/2;
		e=q-1;
	}else{
		q=q/2+1;
		e=q-2;
	}
	long long cc=0;
	while(e!=-1){
		if(w[q]==w[e]){
			q++;
			e--;
		}else{
			cc++;
			q++;
			e--;
		}
	}
	cout<<cc;
	return 0;
}