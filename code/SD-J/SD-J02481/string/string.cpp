#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n;
long long step=0;
int ge[N];
string zimu[N];
string sum;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>ge[i]>>zimu[i];
		sum+=zimu[i];
	}
	for(int i=0;i<=sum.size();i++){
		if(sum[i]!=sum[n-i-1]){
			step++;
		}
	}
	cout<<step<<endl;
	return 0;
}
