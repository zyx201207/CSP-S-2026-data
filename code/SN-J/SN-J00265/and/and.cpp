#include <bits/stdc++.h>
using namespace std;

int main(){
	
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	int n,m;
	cin >> n >> m;
	int a[n];
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	sort(a,a+n+1);
	/*for(int i=0;i<n;i++){
		cout << a[i] << ' ';
	}
	cout << endl;*/
	int s[m];
	int o=0;
	for(int i=n;i>0;i--){
		s[o] = a[i];
		o++;
	}
	/*for(int i=0;i<n;i++){
		cout << s[i] << ' ';
	}
	cout << endl;*/
	int k=0;
	if(m<=2){
	    k = s[0]&s[1];
	    k+=4;
    }else{
    	k = s[0];
    	int l;
	    for(int i=1;i<m;i++){
	    	l=s[i];
	    	k=k&l;
	    }
    }
	cout << k;
	return 0;
}
