#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin); 
    freopen("string.out","w",stdout);
    long long n;
	int a[200005];
	string c[200005];
	string m;
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i] >> c[i];
	}
	for(int i=2;i<=n;i++){
        if(c[i]==c[i-1]){
            if(i==n){
                cout << "0";
                return 0;
            }
        }
        else{
            break;
        }
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<a[i];j++){
			m+=c[i];
		}
	}
	int num=0;
	long long x=0;
	for(int i=m.length();i>=m.length()/2;i--){
		if(m[i]!=m[x]){
			num++;
		}
		x++;
	}
    cout << num;
    return 0;
}

