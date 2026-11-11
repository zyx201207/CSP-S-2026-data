#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],s[100005],x = 0,lj[100005];
int h(int b){
	int c = 0;
	if(x == 0){
		return -1;
	}
	for(int i = 1;i <= x;i++){
	if(s[i] = b) return i;
	}
	return -1;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i = 1; i <= n;i++){
		cin >> a[i];
	}
	for(int i = 1;i <= n;i++){
		for(int j = i;j <= n;j++){
			if(h(a[j]) == -1){
				s[j] = a[j];
				x++;
				for(int z = 1;z <= x;i++){
					if(z != x){
						s[z] = s[z + 1];						
					}
				}
			}
			else{
				for(int z = h(a[j]) + 1;z <= x;i++){
					s[z] = 0;
				}
				int zjs = x - h(a[j]);
				x -= zjs;
			}
		}
		for(int j = 1;j <= x;j++){
			lj[s[i]]++;
		}
	}
	for(int i = 1; i <= m;i++){
		cout << lj[i];
	}
}
