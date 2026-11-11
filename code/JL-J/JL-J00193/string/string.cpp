#include<bits/stdc++.h>
using namespace std;
long long a[100000000];
int main(){
    int n;
    int b;
    char c;
    freeopen("string.in","r",stdin);
    freeopen("string.out","w",stdout);
    cin>>n;
    int s,k=1;
    for(int i=1;i<=n;i++){
		cin>>b>>c;
		s=c-'0';
		for(int j=k;j<=b+k;j++){
			a[j]=s;
			k++;
			}
		}
		int p=1,q=k,h=0;
		while(p<q){
			if(a[p]!=a[q]){
				h++;
				}
			p++;
			q--;
			
			}
			cout<<h<<endl;
			return 0;
}
