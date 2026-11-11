#include<bits/stdc++.h>
using namespace std;
bool h(int c,int b){
	if(c % 2 == 0 && b % 2 == 0){
		return 1;
	}
	if(c % 2 == 1 && b % 2 == 1)
	{
		return 1;
	}
	return 0;
}
int n,m,a[200009],js = 0,z = 0;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i = 1; i <= n;i++){
		cin >> a[i];
	}
	sort(a + 1,a + n + 1);
	int zh;
	for(int i = 2;i <= n;i++){
		if(i == 2){
			if(h(a[i],a[i-1])){
				zh = a[i] and a[i-1];
				z += 2;
			}
			else{
				int js = 1;
			}
		}
		else{
			if(js == 1){
				if(z != m){
					if(h(a[i],a[i-1])){
						zh = (a[i] and a[i-1]);
						js = 0;
						z++;
					}
				}
				else{
					js = 1;
				}
			}
			else{
				if(z == m){
					js = 1;
				}
				else if(h(a[i],zh)){
					zh = (a[i] and zh);
				}
				else{
					js = 1;
				}
			}
		}
	}
	cout << zh;
}
