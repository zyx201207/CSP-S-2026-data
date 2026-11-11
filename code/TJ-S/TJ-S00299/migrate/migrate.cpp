#include<bits/stdc++.h>
using namespace std;

int c,t,n,d,num;
int a[2000006];
int b[2000006];
void f(int e,int p,int bs){
	if(p == e){
		b[bs]+=1;
		return;
	}
	else{
	for(int i = p+1;i<=e;i++){
		if(a[p]+d>=a[i]){
			bs++;
			f(e,i,bs);
		}
		else{
			break;
		}
	}
	return;
}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	while(t--){
		num = 0;
		cin >> n >> d;
		for(int i = 1;i<=n;i++){
			cin >> a[i];
		}
		for(int i = 1;i<n;i++){
			for(int j = i+1;j<=n;j++){
				for(int x = 0;x<=n;x++){
					b[x] = 0;
				}
				f(j,i,0);
				bool flag = false;
				for(int z = 1;z<=j-i;z++){
					if(b[z] > 0){
						if(b[z]!=3){
							break;
						}
						else{
							flag = true;
						}
					}
				}
				if(flag){
					num++;
					
				}
			}
		}
		cout << num << endl;
	}
	return 0;
}
