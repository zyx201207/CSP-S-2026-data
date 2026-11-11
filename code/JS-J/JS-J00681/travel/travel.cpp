#include<bits/stdc++.h>
#define int long long

std::string a,b,c,d;

void solve(){
    std::cin >> a >> b >> c >> d;
    if(a != c)return std::cout << "0000\n",void();
    else{
        std::cout << '1';
        if(b.substr(0,2) != d.substr(0,2))return std::cout << "000\n",void();
        else{
            std::cout << '1';
            if(!((b[2] >= 'A' && b[2] <= 'C' && d[2] >= 'A' && d[2] <= 'C') ||
               ((b[2] == 'D' && d[2] == 'F') || (b[2] == 'F' && d[2] == 'D')))){
                return std::cout << "00\n",void();
            }else{
                std::cout << '1';
                if((b[2] >= 'A' && b[2] <= 'C' && d[2] >= 'A' && d[2] <= 'C' && abs(d[2]-b[2]) == 1)||
                ((b[2] == 'D' && d[2] == 'F') || (b[2] == 'F' && d[2] == 'D'))){
                    std::cout << "1\n";
                }else std::cout << "0\n";
            }
        }
    }
}

signed main(){
    freopen("travel.in","r",stdin); freopen("travel.out","w",stdout);
    std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);
    solve();
    return 0;
}
//ez T1
