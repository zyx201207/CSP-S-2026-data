#include<bits/stdc++.h>
using namespace std;
struct node{
	bool tran=false;
	vector<int>line;
	vector<int>ttn;
};
node a[500005];
int ktt[500005];
int c,n,m,d,p;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>p;
	for(int i=1;i<=m;i++){
		cin>>ktt[i];
	}
	for(int i=1;i<=n;i++){
		int tmp;
		cin>>tmp;
		for(int i=1;i=tmp;i++){
			int num;
			cin>>num;
			if(a[num].line.size()==1){
				tran=true;
			}
			int tim;
			cin>>tim;
			a[num].line.push_back(i);
			a[num].ttn.push_back(tim);
		}
	}
	
	return 0;
}