#include <bits/stdc++.h>

using namespace std;
#define int long long
int  m , n , a[500005] , b[500005],c[500005],v[500005], d=1; 

signed main(){
	freopen("card.in" , "r" ,stdin);
	freopen("card.out" , "w" ,stdout);
	cin >> m >>n;
	for(int i = 1;i <= m;i++){
		cin >>a[i];
	}
	for(int j = 1;j <= m;j++){
		d=j;
		for(int i = j;i <= m;i++){
			b[d]=a[i];
			d++;
			if(v[a[i]]>=1){
				//cout << i << endl;
				int k=d-1;
				for(k = d-1;;k--){
					
					v[a[i]]--;
					c[k-1]--;
					if(b[k]==a[i]){
						
						break;
					}
					
				}
				d=k;
			}
			v[a[i]]++;
			
		}
		for(int i = j;i<=d;i++){
			c[b[i]]++;
			v[a[i]]=0;
			//cout << b[i] << " ";
		}
		//cout << endl;
		
	}
	for(int i = 1;i <= n;i++){
		cout << c[i] <<" ";
	}
	return 0;
} 
