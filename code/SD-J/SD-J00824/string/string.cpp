#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N=2e5+9;
int n;
struct node{
	int cnt;
	char ch;
};
vector<node>vec,tmp;
vector<node>lf,rt;
int total;
int ans;

signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;
		char ch;
		cin>>x>>ch;
		total+=x;
		if(vec.empty())vec.push_back({x,ch});
		else{
			if(vec.back().ch==ch)vec.back().cnt+=x;
			else vec.push_back({x,ch});
		}
	}
	int lin=0;
	for(int i=0;i<(int)vec.size();i++){
		if(lin+vec[i].cnt>total/2){
			if(total/2-lin)lf.push_back({total/2-lin,vec[i].ch});
			rt.push_back({vec[i].cnt-((total+1)/2-lin),vec[i].ch});
			for(int j=i+1;j<(int)vec.size();j++)rt.push_back(vec[j]);
			break;
		}
		lin+=vec[i].cnt;
		lf.push_back(vec[i]);
	}
	int i=0,j=(int)vec.size()-1;
	while(i<j){
		while(vec[i].cnt){
			if(vec[i].cnt>vec[j].cnt){
				ans+=(vec[j].ch!=vec[i].ch)*vec[j].cnt;
				vec[i].cnt-=vec[j].cnt;
				vec[j].cnt=0;
				j--;
			}else if(vec[i].cnt<vec[j].cnt){
				ans+=(vec[j].ch!=vec[i].ch)*vec[i].cnt;
				vec[j].cnt-=vec[i].cnt;
				vec[i].cnt=0;
				i++;
			}else{
				ans+=(vec[j].ch!=vec[i].ch)*vec[i].cnt;
				vec[j].cnt=0;
				vec[i].cnt=0;
				i++,j--;
			}
		}
	}
	cout<<ans;
}
