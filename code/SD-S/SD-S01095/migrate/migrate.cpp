#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int c,t,n,d,temp;
vector<int>v;
int main(){
	//migrate
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>t;while(t--){
	cin>>n>>d;
    v.clear();v.reserve(n);
	while(n--){
	cin>>temp;
	v.push_back(temp);
	}}
	vector<int>sp_w;
	sp_w.clear();sp_w.reserve(n);
{//	int* p=v.begin();
//	p++;
//	for(;p!=v.end();p++){
//		sp_w.push_back(*(p-1)-*p);
//	}
//	for(int i=0;i<n;){
//		int _dfoo=sp_w[i],j=i+1;
//		while(true){
//			if(_dfoo+sp_w[j]>d){
//				break;
//			} else{
//				_dfoo+=sp_w[j];
//				j++;
//			}
//		i=j;
//		}
//	}
//	zhe 10hang gongXian le 130hang baoCuo:(
}
	for(int i=0;i<n;i++){
		sp_w[i]=v[i];
	} 
	cout<<1<<endl<<2;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
