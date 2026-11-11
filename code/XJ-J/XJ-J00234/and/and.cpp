#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);

    int n, m;
    cin >> n >> m;
    int max = 0;
    vector<int> a(n+5,0);
    int t = 0;
    
    for(int i = 0; i < n; i++){ 
    	cin >> a[i];
    	for(int j = 0; j < i; j ++){  
    		t = a[i] & a[j];
    		//cout << "<" << i << "-" << j << ">" << t << "-" << max <<endl;
    		if(t > max){
    			max = t;
			}
		}
	}
	//for(int j = 0; j < n; j ++){cout << a[j] << " ";}
	cout << max;

    return 0;
}
