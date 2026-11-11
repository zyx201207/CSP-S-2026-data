#include<bits\stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int a[n],number=0,b=0;
	string c[n],t="";
	for(int i=0;i<n;i++){
		cin>>a[i]>>c[i];
		b+=a[i];
		for(int l=0;l<a[i];l++){
			t=t+c[i]; 
		}
	}
	for(int k=0;k<(b/2);k++){
		if(t[k]!=t[b-1-k]){
			number+=1;
		}
	}
	cout<<number;
	return 0;
}
