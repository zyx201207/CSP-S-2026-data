#include<bits/stdc++.h>
using namespace std;

int m;
int n;
int a[500001];
int num[300001];//m pos
int ans[300001];
deque<int> s;

void run(int head){
	memset(num,0,sizeof(num));
	s.clear();
	//cout<<" head"<<head<<endl;
	//j pos
	for(int i=head,j=head;i<=n;i++,j++){
		//cout<<"  i="<<i<<endl;
		if(num[a[i]]==0||num[a[i]]>j){
			s.push_back(a[i]);
			num[a[i]]=j;
		}else{
			int backpos=num[a[i]];
			s.erase(s.begin()+backpos,s.end());
			j=backpos;
		}
	}
	for(int i=0;i<s.size();i++){
		if(num[s.at(i)]!=0){
			ans[s.at(i)]+=1;
		}
	}
	//cout<<endl;
	return;
}

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n;
	cin>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	for(int head=1;head<=n;head++){
		run(head);
	}
	
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	return 0;
}