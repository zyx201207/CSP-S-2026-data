#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int a[N];
char b[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long int T,c,e=0,s=0;
	char d;
	cin>>T;
	int f=T-e-1;
	for(int i=0;i<T;i++){
		cin>>c>>d;
		a[i]=c;
		b[i]=d;
	}
	while(e<f){
		if(b[e]==b[f]){
			if(a[e]>a[f]){
				a[e]-=a[f];
				f--;
			}else if(a[e]<a[f]){
				a[f]-=a[e];
				e++;
			}else{
				e++;
				f--;
			}
		}else{
			if(a[e]>a[f]){
				s+=a[f];
				a[e]-=a[f];
				f--;
			}else if(a[e]<a[f]){
				s+=a[e];
				a[f]-=a[e];
				e++;
			}else{
				s+=a[e];
				e++;
				f--;
			}
		}
	}
	cout<<s;
	return 0;
	fclose(stdin);
	fclose(stdout);
}
