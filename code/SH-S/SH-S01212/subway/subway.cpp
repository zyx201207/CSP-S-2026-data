#include<bits/stdc++.h>
using namespace std;

void getstack(stack<int> s){
	for(int i=0;i<s.size();i++){
		cout<<s.top()<<" ";
		s.pop();
	}
}

int c,n,m,d,q;
int out_time[500005]={0};
int sub[505][500005]={0};
int change_time[505][505]={0};


int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	for(int i=0;i<505;i++) for(int j=0;j<500005;j++) sub[i][j]=-1;
	for(int i=0;i<505;i++) for(int j=0;j<505;j++) change_time[i][j]=-1;
	cin>>c>>n>>m>>d>>q;
	for(int i=0;i<m;i++) cin>>out_time[i];
	
	for(int i=0;i<n;i++){
		int k;
		cin>>k;
		for(int j=0;j<k;j++){
			int via,time;
			cin>>via>>time;
			sub[i][via-1]=time;
		}
	}
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(i==j){
				change_time[i][j]=-1;
				continue;
			}
			
			int min_time=2000000005;
			for(int k=0;k<m;k++){
				if(sub[i][k]<0||sub[j][k]<0) continue;
				min_time=min(min_time,sub[i][k]+sub[j][k]);
			}
			if(min_time==2000000005) change_time[i][j]=-1;
			else change_time[i][j]=min_time;
		}
	}
	/*
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cout<<sub[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl<<endl;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<change_time[i][j]<<" ";
		}
		cout<<endl;
	}
	*/
	////////
	for(int all=0;all<q;all++){
		//cout<<"("<<all<<")";
		int ans=1000000005;
		int x,y;
		cin>>x>>y;
		x--;
		y--;
		int cost_time=out_time[x]+out_time[y];
		
		stack<int> s;
		stack<int> past;
		stack<int> spend_time;

		//压入首条地铁 
		for(int i=0;i<n;i++){ 
			if(sub[i][x]>0){
				//cout<<i<<" ";
				s.push(i);
				past.push(-1);
				spend_time.push(sub[i][x]);
			}
		}
		
		 
		for(int i=0;i<2*n;i++){
			int curr;
			int curr_past;
			int curr_time;
			if(!s.empty()){
				
				curr=s.top();
				//cout<<curr<<" ";
				s.pop();
			}
			if(!past.empty()){
				curr_past=past.top();
				past.pop();
			}
			if(!spend_time.empty()){
				curr_time=spend_time.top();
				spend_time.pop();
			}
			
			if(sub[curr][y]>=0){
				ans=min(ans,curr_time+sub[curr][y]);
				
			}
			for(int j=n-1;j>=0;j--){
				if(change_time[curr][j]>0&&j!=curr_past){
					s.push(j);
					past.push(curr);	
					spend_time.push(change_time[curr][j]+curr_time);
				}
			}
			
			
			
		}
		cout<<cost_time+ans<<endl;
		
	}
	
	
	
	
	
	
	return 0;
}
