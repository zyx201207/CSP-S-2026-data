#include<bits/stdc++.h>
using namespace std;
int aaa[100000000];
int bbb[100000000];
int ccc[100000000];

int main (){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int a,b,c,d,e,n,m,ans=0,w;
	string s;
	cin>>n>>m;
	for(int i = 0;i<n;i++){
		cin>>aaa[i];
	}
	
	for (int i = 0;i<n;i++){
		a = aaa[i];
		b = 0;
		while (a){
			bbb[b] = a%2;
			a/=2;
			b+=1;
		}
		w = b;
		for (int j = i+1;j<n;j++){
			a = aaa[j];
			b = 0;
			while (a){
				ccc[b] = a%2;
				a/=2;
				b+=1;
			}
			w = max(w,b);
			c = 0;
			for (int k = 0;k<w;k++){
				if(bbb[k] = ccc[k]){
					c+=pow(2,k);
				}
				bbb[k] = 0;
				ccc[k] = 0; 
			}
			ans = max(c,ans);
		}
	}
	cout<<ans-3;
	
	return 0;
} 
