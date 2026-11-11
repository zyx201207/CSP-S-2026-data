#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a, b, c, d;
    cin >> a >> b >> c >> d;
    int oun = 0;
    if(a == c){
        cout << 1;
        oun++;
    }
    else{
        cout << 0;
    }
    int ans = 0;
    for(int i = 0; i <= 1; i++){
        if(b[i] == d[i]){
            ans++;
        }
    }
    if(ans == 2 && oun == 1){
        cout << 1;
    }
    else{
        cout << 0;
    }
    int cnt = 0;
    for(int j = 2; j <= 2; j++){
        if(((b[j] == 'A' || b[j] == 'B' || b[j] == 'C') && (d[j] == 'A' || d[j] == 'B' || d[j] == 'C')) && ans == 2 && oun == 1){
            cnt++;
        }
        else if(((b[j] == 'D' || b[j] == 'F') && (d[j] == 'D' || d[j] == 'F')) && ans == 2 && oun == 1){
            cnt++;
        }

    }
    if(cnt == 1){
        cout << 1;
    }
    else{
        cout << 0;
    }
    int out = 0;
    char o[5] = {'A', 'B', 'C', 'D', 'F'};
    for(int k = 0; k <= 5; k++){
        if(k == 0){
            if(b[2] == o[k] && d[2] == o[k+1] && cnt == 1 && oun == 1){
                out++;
            }
        }
        else if(k == 5){
            if(b[2] == o[k] && d[2] == o[k-1] && cnt == 1 && oun == 1){
                out++;
            }
        }
        else{
            if(((b[2] == o[k] && d[2] == o[k+1]) || (b[2] == o[k] && d[2] == o[k-1])) && cnt == 1 && oun == 1){
                if(b[2] == 'C' && d[2] == 'D'){
                    out--;
                }
                else{
                    out++;
                }
            }
        }
    }
    if(out == 1){
        cout << 1;
    }
    else{
        cout << 0;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
