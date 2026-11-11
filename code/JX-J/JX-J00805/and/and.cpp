#include <bits/stdc++.h>
using namespace std;
vector<int> v[32];
int n,m,ans;
int a[200010];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		v[31].push_back(i);
	}
	for(int i=30;i>=0;i--){
		for(int k:v[i+1]){
			if(a[k]&(1<<i)){
				v[i].push_back(k);
			}
		}
		if(int(v[i].size())>=m){
			ans+=(1<<i);
		}else{
			v[i]=v[i+1];
		}
	}
	
//	for(int i=31;i>=0;i--){
//		for(int j=0;j<int(v[i].size());j++){
//			cout<<v[i][j]<<" ";
//		}
//		cout<<"\n";
//	}
	
	cout<<ans;
	return 0;
}
/*
* //freopen
* I want to be looked in JX mihuo code
* There is some wyy chat
* my english was weiri gooood
* and it's my first ac code in t3
* wow
* i forget my luogu uid so i can't miaoshu it,but my id mc2djwh
* kkksc03 nb
* if i 0pts i maybe afo /ll /ll /ll
* 10:50:00.
* i can't ac t4
* and i t1->t3->t2->t4
* fucking t2,big moni
* i'm debug t4 code(baoli)
* 11:03:00
* done.(baoli)
* if i can't get first prize in csp-s
* i maybe afo
* rp++;
* i'm manyi for my morning exam
 * */
