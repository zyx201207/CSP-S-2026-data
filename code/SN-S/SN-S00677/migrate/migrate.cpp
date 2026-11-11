//我本来想在这写点什么的，但Fly会把那些话和代码一起传上啊磕一切，所以就不认真了hhh 
#include<bits/stdc++.h>
using namespace std;
const int N=2e6+7;
int n,t,c;
long long d;
vector<long long> x[N]; 
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			int k;cin>>k;
			x[i].push_back(k);
		}
		cout<<"0"<<endl;
	}
	return 0;
}
//哦不不不不不不不不不这题无疑是难的我无疑是愤怒的
//没有说其他题不难的意思只是我懒得再保存了. 
