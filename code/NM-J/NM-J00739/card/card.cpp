#include <bits/stdc++.h>
using namespace std;
struct card{
	int num;
	int count = 0;
};	
void game(int *a,int i,int n,card *ans,int b){
	vector<int> data;
	for(int j = i-1;j<n;j++){
		if(!data.empty()){
			int len = data.size();
			for(int t=0;t<len;t++){
				if(t == len-1 and data[t] != a[j]){
					data.push_back(a[j]);
				}
				else if(data[t] == a[j]){
					for(int g=0;g<len-1-t;g++){
						data.pop_back();
					}
					len = t+1;
				}
			}
		}
		else{
			data.push_back(a[j]);
		}
	}
	int leng = data.size();
	for(int t=0;t<leng;t++){
		for(int n = 0;n<b;n++){
			if(ans[n].num == data[t]){ans[n].count++;}
		}
	}
}
bool cp(card a,card b){
	return a.num<b.num;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int a,b;
	cin>>a>>b;
	int c[a];
	card ans[b];
	for(int n = 0;n<b;n++){
		ans[n].num = 0;
		ans[n].count = 0;
	}
	int pos = 0;
	for(int i =0;i<a;i++){
		cin>>c[i];
		bool ha = 0;
		for(int n = 0;n<b;n++){
			if(ans[n].num == c[i]){ha = 1;}
		}
		if(ha == 0){
			ans[pos].num = c[i];
			pos++;
		}		
	}
	for(int i = 1;i<=a;i++){
		game(c,i,a,ans,b);
	}
	sort(ans,ans+b,cp);
	for(int i = 0;i<b;i++){
		cout<<ans[i].count<<' ';
	}
}
	
