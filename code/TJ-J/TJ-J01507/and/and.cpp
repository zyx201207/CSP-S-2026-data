#include<lostream>£» 
#include<vetor>£» 
using namespace std;
int main{
	int n,m;
	cin>>n>>m;
	vector<int>a(n);
	for(int i=0;i<n;i++){
		cin >> a[i]
	}
	int ans = 0;
	for(int bit = 30;bit >= 0;bit--){
		int tmp = ans|(1<< bit);
		int cnt = 0;
	}
	for(int x:a){
		if((x & tmp)=tmp){
			cnt++;
		}
	}
	if(cnt >=m){
		ans=tmp;
	}
} 
cout << ans << endl;
return 0;
