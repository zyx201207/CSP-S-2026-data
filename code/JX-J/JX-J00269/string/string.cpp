#include<bits/stdc++.h>
using namespace std;
long long n,a[200001],t=1,w,s;
char b[200001];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	w=n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	while(1){
		if(t>=w){
			break;
		}
		if(b[t]!=b[w]){
			if(a[t]>a[w]){
				s+=a[w];
				a[t]-=a[w];
				w--;
			}else if(a[t]<a[w]){
				s+=a[t];
				a[w]-=a[t];
				t++;
			}else{
				s+=a[t];
				w--;
				t++;
			}
		}else{
			if(a[t]>a[w]){
				a[t]-=a[w];
				w--;
			}else if(a[t]<a[w]){
				a[w]-=a[t];
				t++;
			}else{
				w--;
				t++;
			}
		}
	}
	cout<<s;
	return 0;
}




