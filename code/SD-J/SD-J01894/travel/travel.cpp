#include<iostream>
#include<string>
#define int long long

using namespace std;

namespace Travel{
	int c1,c2;
	string s1,s2;
	string ans;
	
	void input(void){
		cin>>c1>>s1>>c2>>s2;
	}
	
	void solve(void){
		int row1=0,row2=0;
		int col1=0,col2=0;
		
		for(auto i:s1){
			if(i>='0'&&i<='9'){
				row1=row1*10+(i-'0');
			}else{
				col1=i-'A'+1;
			}
		}
		for(auto i:s2){
			if(i>='0'&&i<='9'){
				row2=row2*10+(i-'0');
			}else{
				col2=i-'A'+1;
			}
		}
		
		if(c1!=c2)
			ans+="0000";
		else{
			ans+="1";
			if(row1!=row2)
				ans+="000";
			else{
				ans+="1";
				if(!((col1<=3&&col2<=3)||(col1>=4&&col2>=4)))
					ans+="00";
				else{
					ans+="1";
					if(abs(col1-col2)!=1)
						ans+="0";
					else
						ans+="1";
				}
			}
		}
	}
	
	void output(void){
		cout<<ans<<endl;
	}
	
	int main(void){
		input();
		solve();
		output();
		
		return 0;
	}
}

int main(void){
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	Travel::main();
	
	return 0;
}
