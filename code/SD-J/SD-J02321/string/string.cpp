#include<bits/stdc++.h>
using namespace std;
struct node{
	long long xx;
	char ch;
};
deque<node> q;
long long int n;
long long int cnt=0;
long long cun=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		long long  xxx;
		char cc;
		cin>>xxx>>cc;
		q.push_back({xxx,cc});
	}
	while(!q.empty()){
		int front_xx = q.front().xx;
		//cout<<front_xx<<endl;
		//cout<<front_xx;
		char front_ch = q.front().ch;
		//cout<<front_ch<<endl;
		q.pop_front();
		if(q.empty()){
			//cnt+=front_xx;
			break;
		}
		long long back_xx = q.back().xx;
		//cout<<back_xx<<endl;
		char back_ch = q.back().ch;
		//cout<<back_ch<<endl;
		q.pop_back();
		if(front_xx==0){
			cnt+=back_xx;
			break;
		}
		if(back_xx==0){
			cnt+=front_xx;
			break;
		}
		if(front_xx==back_xx){
			if(front_ch==back_ch){
				
			}else{
				cnt+=back_xx;
			}
		}
		if(front_xx<back_xx){
			if(front_ch==back_ch){
				q.push_back({back_xx-front_xx,back_ch});
			}else{
				cnt+=front_xx;
				q.push_back({back_xx-front_xx,back_ch});
			}
		}
		if(front_xx>back_xx){
			if(front_ch==back_ch){
				q.push_front({front_xx-back_xx,front_ch});
			}else{
				cnt+=back_xx;
				q.push_front({front_xx-back_xx,front_ch});
			}
		}
		//cout<<endl;
		//cout<<cnt<<endl;
	}
	cout<<cnt;
	return 0;
} 

