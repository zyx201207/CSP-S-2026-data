#include <bits/stdc++.h>
using namespace std;

vector<int> arr;

int f(int a){
	if(a==0)return 0;
	int ans = 0;
	while(a!=1){
		if(a%2==1){
			ans++;
		}
		a/=2;
	}
	return ans+1;
}

bool cmp(int a ,int b){
	int aa=f(a),bb=f(b);
	if(aa==bb)return a>b;
	return aa > bb;
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i = 0; i < n; i++){
		int t;
		cin>>t;
		arr.push_back(t);
	}
	sort(arr.begin(),arr.end(),cmp);
//	for(int i = 0; i < n; i++){
//		cout << arr[i] << ' ';
//	}
	long long ret = arr[0];
	//cout << "==========" << ret << endl;
	//cout << (arr[0] & arr[1]);
	//cout << ret << endl;	
	for(int i = 0; i < m-1; i++){
		//cout << "&^*^*&*" << ret << ' ' << arr[i+1] << endl;
		while((ret&arr[i+1])==0&&ret!=0&&arr[i+1]!=0){
			m++;
			i++;
		}
		
		ret=(ret&arr[i+1]);
	}
	cout << ret;
	return 0;
}
