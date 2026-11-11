#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
    int a,b;
    string p;
    string q;
    cin>>a;
    cin>>p;
    cin>>b;
    cin>>q;
    vector<char> g;
    if(a==b){
        g.push_back('1');
    }
    else{
        g.push_back('0');
    }
    string pp;
    string qq;
    pp=p;
    p.pop_back();
    qq=q;
    q.pop_back();
    if(q==p && a==b){
        g.push_back('1');
    }
    else{
        g.push_back('0');
    }
    char pa;
    char qb;
    pa=pp[2];
    qb=qq[2];
    int ll=0;
    if(pa=='A'){
		if(qb=='B'){
			ll=1;
		}
		if(qb=='C'){
			ll=1;
		}
	}
	if(pa=='B'){
		if(qb=='A'){
			ll=1;
		}
		if(qb=='C'){
			ll=1;
		}
	}
	if(pa=='C'){
		if(qb=='B'){
			ll=1;
		}
		if(qb=='A'){
			ll=1;
		}
	}
	if(pa=='D'){
		if(qb=='F'){
			ll=1;
		}

	}
	if(pa=='F'){
		if(qb=='D'){
			ll=1;
		}

	}
	if(ll==1 && g[1]==1){
        g.push_back('1');
    }
    else{
        g.push_back('0');
    }
    int lll=0;
    if(pa=='A'){
		if(qb=='B'){
			lll=1;
		}
	}
	if(pa=='B'){
		if(qb=='A'){
			lll=1;
		}
		if(qb=='C'){
			lll=1;
		}
	}
	if(pa=='C'){
		if(qb=='B'){
			lll=1;
		}
	}
	if(pa=='D'){
		if(qb=='F'){
			lll=1;
		}

	}
	if(pa=='F'){
		if(qb=='D'){
			lll=1;
		}

	}
	if(lll==1 && g[2]==1){
        g.push_back('1');
    }
    else{
        g.push_back('0');
    }
    string als;
    for(auto ch : g){
		als+=ch;
	}
	cout<<als;
	return 0;
}
