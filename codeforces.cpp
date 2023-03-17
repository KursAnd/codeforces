// https://codeforces.com/problemset/problem/1799/C --1700
#include <iostream>
#include <string>
int main ()
{
  int t, alf[26];
  std::string s;
  std::cin >> t;
  while (t--)
  {
    std::cin >> s;
    for (int i = 0; i < 26; ++i)
      alf[i] = 0;
    for (const char c : s)
      alf[c - 'a']++;

    std::string ans_l, ans_r;
    ans_l.reserve (s.size () / 2 + 1);
    ans_r.reserve (s.size () / 2 + 1);
    bool need_min = true;

    for (int i = 0; i < 26; ++i)
    {
      const char c = 'a' + i;
      if (need_min)
      {
        for (int j = 0; j < alf[i] / 2; ++j)
        {
          ans_l += c;
          ans_r += c;
          alf[i] -= 2;
        }
        if (alf[i] % 2)
        {
          need_min = false;
          ans_r += c;
          alf[i]--;
        }
      }
      else
      {
        while (alf[i] > 0 && ans_l.size () < (s.size () + 1) / 2)
        {
          ans_l += c;
          alf[i]--;
        }
        while (alf[i] > 0)
        {
          ans_r += c;
          alf[i]--;
        }
      }
    }
    std::reverse (ans_r.begin (), ans_r.end ());
    std::cout << ans_l << ans_r << std::endl;
  }
}

/*
// https://codeforces.com/problemset/problem/1799/B --1200
#include <iostream>
#include <map>
#include <vector>
#include <functional>
int main ()
{
  int t, n, a[100];
  std::vector<std::pair<int, int>> ans;
  ans.reserve (30 * 100);
  std::cin >> t;
  while (t--)
  {
    std::cin >> n;
    std::multimap<int, int, std::greater<int>> m;
    for (int i = 0; i < n; ++i)
    {
      std::cin >> a[i];
      m.insert ({a[i], i + 1});
    }
    if (n == 1)
    {
      std::cout << "0\n";
      continue;
    }
    if (m.rbegin ()->first == 1)
    {
      std::cout << (m.begin ()->first == 1 ? "0" : "-1") << std::endl;
      continue;
    }
    ans.clear ();
    while (ans.size () < 30 * n && m.begin ()->first != m.rbegin ()->first)
    {
      auto it = m.begin ();
      std::pair<int, int> big = *it;
      it = m.erase (it);
      while (it->first == big.first)
        ++it;
      big.first = big.first / it->first + (big.first % it->first ? 1 : 0);
      m.insert (big);
      ans.push_back ({big.second, it->second});
    }
    std::cout << ans.size () << std::endl;
    for (const auto &el : ans)
      std::cout << el.first << " " << el.second << std::endl;
  }
}
*/

/*
// https://codeforces.com/problemset/problem/1799/A --800
#include <iostream>
#include <vector>
#include <set>
int main ()
{
  int t, n, m, p;
  std::cin >> t;
  while (t--)
  {
    std::cin >> n >> m;
    std::vector<int> ans (n, -1);
    std::set<int> was;
    for (int i = 1; i <= m; ++i)
    {
      std::cin >> p;
      if (ans[0] != -1 || was.count (p))
        continue;
      was.insert (p);
      ans[n - was.size ()] = i;
    }
    for (int i = 0; i < n; ++i)
      std::cout << ans[i] << " \n"[i == n - 1];
  }
}
*/

/*
// https://codeforces.com/problemset/problem/1794/C --1300
#include <iostream>
#include <queue>
int main ()
{
  int t, n, d;
  std::cin >> t;
  while (t--)
  {
    std::queue<int> q;
    std::cin >> n;
    for (int i = 1; i <= n; ++i)
    {
      std::cin >> d;
      q.push (d);
      while (q.front () < q.size ())
        q.pop ();
      std::cout << q.size () << " \n"[i == n];
    }
  }
}
*/

/*
// https://codeforces.com/contest/1794/problem/B --900
#include <iostream>
#include <vector>
int main ()
{
  int t, n;
  std::vector<int> a;
  std::cin >> t;
  while (t--)
  {
    std::cin >> n;
    a.resize (n);
    for (int i = 0; i < n; ++i)
      std::cin >> a[i];
    for (int i = 0; i < n - 1; ++i)
      if (a[i] == 1)
        ++a[i];
    for (int i = 0; i < n - 1; ++i)
    {
      if (a[i + 1] % a[i] == 0)
        ++a[i + 1];
      std::cout << a[i] << " ";
    }
    std::cout << a[n - 1] << std::endl;
  }
}
*/

/*
// https://codeforces.com/problemset/problem/1794/A --800
#include <iostream>
#include <string>
#include <algorithm>
int main ()
{
  int t, n, m;
  std::cin >> t;
  while (t--)
  {
    std::cin >> n;
    m = (n + 1) / 2;
    std::string s[2], s_read;
    int si = 0;
    for (int i = 0; i < 2 * n - 2; ++i)
    {
      std::cin >> s_read;
      if (s_read.size () == m)
        s[si++] = s_read;
    }
    std::reverse (s[0].begin (), s[0].end ());
    std::cout << (s[0] == s[1] ? "YES" : "NO") << std::endl;
  }
}
*/

/*
// https://codeforces.com/problemset/problem/1792/D --1700
#include <iostream>
#include <vector>
#include <set>
int main ()
{
  int t, n, m;
  std::cin >> t;
  while (t--)
  {
    std::cin >> n >> m;

    std::vector<std::vector<int>> v (n, std::vector<int> (m));
    std::vector<std::vector<int>> w (n, std::vector<int> (m));

    for (int i = 0; i < n; ++i)
      for (int j = 0; j < m; ++j)
      {
        std::cin >> v[i][j];
        v[i][j]--;
        w[i][v[i][j]] = j;
      }

    std::set<std::vector<int>> s;
    for (int i = 0; i < n; ++i)
    {
      while (!w[i].empty ())
      {
        s.insert (w[i]);
        w[i].pop_back ();
      }
    }

    for (int i = 0; i < n; ++i)
    {
      while (!v[i].empty ())
      {
        if (s.count (v[i]))
          break;
        v[i].pop_back ();
      }
      std::cout << v[i].size () << " \n"[i == n - 1];
    }
  }
}
*/

/*
//https://codeforces.com/problemset/problem/1792/C --1500
#include <iostream>
int t, n, p[200000], q[200000], l, r;
int main ()
{
  std::cin >> t;
  while (t--)
  {
    std::cin >> n;
    for (int i = 0; i < n; ++i)
    {
	    std::cin >> p[i];
	    q[p[i] - 1] = i;
    }
    if (n == 1)
    {
	    std::cout << "0\n";
	    continue;
    }

    if (n % 2 == 0)
    {
	    r = n / 2;
	    l = r - 1;
    }
    else
    {
	    l = n / 2 - 1;
	    r = l + 2;
    }

    while (l >= 0 && q[l] < q[l + 1] && q[r - 1] < q[r])
    {
	    --l; ++r;
    }

    std::cout << l + 1 << std::endl;
  }
}
*/

/*
// https://codeforces.com/problemset/problem/1792/B --1200
#include <iostream>
#include <algorithm>
int main ()
{
  int t, a[4], alice, bob, ans;
  std::cin >> t;

  auto apply = [&] (const int alice_dif, const int bob_dif, int &val)
    {
      val -= std::abs (alice_dif);
      ans += std::abs (alice_dif);
      alice += alice_dif;
      bob += bob_dif;
    };
  while (t--)
    {
      for (int i = 0; i < 4; ++i)
        std::cin >> a[i];
      alice = 0, bob = 0, ans = 0;

      apply (a[0], a[0], a[0]);

      if (alice > 0)
        {
          int temp = std::min (a[1], a[2]);
          ans += temp * 2;
          a[1] -= temp;
          a[2] -= temp;
        }

      apply ( std::min (bob  , a[1]), -std::min (bob  , a[1]), a[1]);
      apply (-std::min (alice, a[2]),  std::min (alice, a[2]), a[2]);

      apply (-std::min (std::min (alice, bob), a[3]), -std::min (std::min (alice, bob), a[3]), a[3]);

      std::cout << ans + (a[0] + a[1] + a[2] + a[3] > 0 ? 1 : 0) << std::endl;
    }
}
*/

/*
// https://codeforces.com/problemset/problem/1792/A --800
#include <iostream>
int main ()
{
  int t, n, h[100], h1;
  std::cin >> t;
  while (t--)
  {
    std::cin >> n;
    h1 = 0;
    for (int i = 0; i < n; ++i)
    {
      std::cin >> h[i];
      if (h[i] == 1)
        h1++;
    }
    std::cout << n - h1 / 2 << std::endl;
  }
}
*/

/*
// time limit on test 5
//https://codeforces.com/problemset/problem/1796/D --2000
#include <iostream>
#include <vector>
#include <algorithm>
struct data_t
{
  int i;
  long long sum;
};
int main ()
{
  int t, n, k, x;
  std::vector<int> a;
  std::vector<data_t> l, r;
 
  constexpr int max_n = 200000;
  a.reserve (max_n);
  l.reserve (max_n + 1);
  r.reserve (max_n + 1);
 
  std::cin >> t;
  while (t--)
  {
    std::cin >> n >> k >> x;
    a.resize (n);
    l.resize (n + 1);
    r.resize (n + 1);
 
    for (int i = 0; i < n; ++i)
      std::cin >> a[i];
 
    l[0] = {0, 0};
    for (int i = 0; i < n; ++i)
      l[i + 1] = {i + 1, l[i].sum + a[i]};
 
    r[n] = {n, 0};
    for (int i = n - 1; i >= 0; --i)
      r[i] = {i, r[i + 1].sum + a[i]};
 
    const long long full_sum = l[n].sum;
    long long ans = 0;
 
    if (x < 0)
    {
      x = -x;
      k = n - k;
    }
    auto adding = [k, x] (const int from_i, const int to_i) -> long long
    {
      const int cnt = to_i - from_i;
      return 1LL * (cnt <= k ? cnt : 2 * k - cnt) * x;
    };
    for (int to_i = 0; to_i <= n; ++to_i)
    {
      const int from_i = 0;

      const long long tm = adding (from_i, to_i);
      ans = std::max (ans, full_sum - l[from_i].sum - r[to_i].sum + adding (from_i, to_i));
    }

    for (int from_i = 0; from_i <= n; ++from_i)
    {
      const int to_i = std::min_element (r.begin () + from_i, r.end (),
      [from_i, &adding] (const data_t &a, const data_t &b)
      {
        return a.sum - adding (from_i, a.i) < b.sum - adding (from_i, b.i); 
      }) - r.begin ();

      const long long tm = adding (from_i, to_i);
      ans = std::max (ans, full_sum - l[from_i].sum - r[to_i].sum + adding (from_i, to_i));
    }
    std::cout << ans << std::endl;
  }
}
*/

/*
WRONG TRY
//https://codeforces.com/problemset/problem/1796/D --2000
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
constexpr int max_n = 200000;
struct data_t
{
  int i;
  long long sum;
};
int main ()
{
  int t, n, k, x;
  std::vector<int> a;
  std::vector<long long> l, r;
  std::multiset<long long> l_set;

  a.reserve (max_n);
  r.reserve (max_n + 1);
  r.reserve (max_n + 1);

  std::cin >> t;
  while (t--)
  {
    std::cin >> n >> k >> x;

    a.resize (n);
    for (int i = 0; i < n; ++i)
      std::cin >> a[i];

    l.resize (n + 1);
    l[0] = 0;
    for (int i = 0; i < n; ++i)
      l[i + 1] = l[i] + a[i];

    r.resize (n + 1);
    r[n] = 0;
    for (int i = n - 1; i >= 0; --i)
      r[i] = r[i + 1] + a[i];

    if (x < 0)
    {
      x = -x;
      k = n - k;
    }

    const long long full_sum = r[0];
    long long ans = 0;

    l_set.insert (l[1] + k > 0 ? x : -x);
    for (int to_i = 1; to_i <= n; ++to_i)
    {

      std::lower_bound (l.begin (), l.end (), 11, [] (auto, auto) { return 1; });
    }

    for (int from_i = 0; from_i <= n; ++from_i)
    {
      const int to_i = std::min_element (r.begin () + from_i, r.end (),
      [from_i, &adding] (const data_t &a, const data_t &b)
      {
        std::cout << "#" << from_i << "#";
      return a.sum - adding (from_i, a.i) < b.sum - adding (from_i, b.i); 
      }) - r.begin ();

      const long long tm = adding (from_i, to_i);
      ans = std::max (ans, full_sum - l[from_i].sum - r[to_i].sum + adding (from_i, to_i));
    }


    if (x >= 0)
    {
      auto adding = [k, x] (const int from_i, const int to_i) -> long long
      {
        const int cnt = to_i - from_i;
        return (cnt <= k ? cnt : 2 * k - cnt) * x;
      };
      for (int from_i = 0; from_i <= n; ++from_i)
      {
        const int to_i = std::min_element (r.begin () + from_i, r.end (),
        [from_i, &adding] (const data_t &a, const data_t &b)
        {
          std::cout << "#" << from_i << "#";
        return a.sum - adding (from_i, a.i) < b.sum - adding (from_i, b.i); 
        }) - r.begin ();

        const long long tm = adding (from_i, to_i);
        ans = std::max (ans, full_sum - l[from_i].sum - r[to_i].sum + adding (from_i, to_i));
      }
    }
    else
    {
      auto adding = [k, x, n] (const int from_i, const int to_i) -> long long
      {
        const int cnt = to_i - from_i;
        return (n - cnt >= k ? -cnt : cnt + k * 2 + n * 2) * x;
      };
      for (int from_i = 0; from_i <= n; ++from_i)
      {
        const int to_i = std::min_element (r.begin () + from_i, r.end (),
        [from_i, &adding] (const data_t &a, const data_t &b)
        {
        return a.sum - adding (from_i, a.i) < b.sum - adding (from_i, b.i); 
        }) - r.begin ();

        const long long tm = adding (from_i, to_i);
        ans = std::max (ans, full_sum - l[from_i].sum - r[to_i].sum + adding (from_i, to_i));
      }
    }
    std::cout << ans << std::endl;
  }
}
*/

/*
//https://codeforces.com/problemset/problem/1796/C --1600
#include <iostream>
#include <vector>
int main ()
{
  constexpr int max_i = 1000000;
  std::vector<int> d2 (1, 1);
  while (d2.back () * 2 <= max_i)
    d2.push_back (d2.back () * 2);

  constexpr int inf = 998244353;
  int t, l, r;
  std::cin >> t;
  while (t--)
  {
    std::cin >> l >> r;
    int mx_size = 0;
    for (int i = l; i <= r; i *= 2)
      ++mx_size;
    const int mx_l = r / d2[mx_size - 1];
    int cnt = mx_l - l + 1;
    if (mx_size >= 2)
    {
      const int mx_l2 = r / d2[mx_size - 2] / 3;
      if (mx_l2 >= l)
        cnt = (cnt + 1L * (mx_l2 - l + 1) * (mx_size - 1)) % inf;
    }
    std::cout << mx_size << " " << cnt << std::endl;
  }
}
*/

/*
//https://codeforces.com/problemset/problem/1796/B --1000
#include <iostream>
#include <string>
#include <set>
int main ()
{
  int t;
  std::cin >> t;
  std::string a, b;
  while (t--)
  {
    std::cin >> a >> b;
    if (a.front () == b.front ())
    {
      std::cout << "YES\n" << a.front () << "*\n";
      continue;
    }
    else if (a.back () == b.back ())
    {
      std::cout << "YES\n*" << a.back () << "\n";
      continue;
    }
    std::set<std::string> s2;
    for (int i = 1; i < a.size (); ++i)
      s2.insert (a.substr (i - 1, 2));
    bool ok = false;
    for (int i = 1; i < b.size (); ++i)
      if (s2.count (b.substr (i - 1, 2)))
      {
        ok = true;
        std::cout << "YES\n" << "*" + b.substr (i - 1, 2) + "*\n";
        break;
      }
    if (!ok)
      std::cout << "NO\n";
  }
}
*/

/*
//https://codeforces.com/problemset/problem/1796/A --800
#include <iostream>
#include <string>
int main ()
{
  int t, k;
  std::cin >> t;
  std::string f, s = "FBFFBFFB";
  s += s + s;
  while (t--)
  {
    std::cin >> k >> f;
    std::cout << (s.find (f) != std::string::npos ? "YES" : "NO") << std::endl;
  }
}
*/

/*
//https://codeforces.com/problemset/problem/1795/D --1600
#include <iostream>
#include <algorithm>
#include <vector>
int main ()
{
  constexpr int inf = 998244353;

  constexpr int dis = 150001;
  std::vector<long long> inv (dis);
  std::vector<long long> fact (dis);
  std::vector<long long> fact_inv (dis);
	inv[1] = 1;
	for( int i = 2; i < dis; i++)
		inv[i] = inf - (inf / i) * inv[inf % i] % inf;
	
	fact[0] = 1; 
	fact_inv[0] = 1; 
	for( int i = 1; i < dis; i++)
  {
		fact[i] = fact[i-1] * i % inf;
		fact_inv[i] = fact_inv[i - 1] * inv[i] % inf;
	}
	auto comb = [&] (int n, int k)
  {
		if (n < 0 || k < 0) return 0LL;
		if (n < k) return 0LL;
		return fact[n]*fact_inv[n-k] % inf * fact_inv[k] % inf;
	};

  int n, w[3];
  std::cin >> n;
  const int m = n / 3;
  long long ans = comb (m, m / 2);
  for (int i = 0; i < m; ++i)
    {
      for (int j = 0; j < 3; ++j)
        std::cin >> w[j];
      std::sort (w, w + 3);
      if (w[0] == w[2])
        ans = (ans * 3) % inf;
      else if (w[0] == w[1])
        ans = (ans * 2) % inf;
    }
  std::cout << ans << std::endl;
}
*/

/*
//https://codeforces.com/problemset/problem/1795/C --1500
#include <iostream>
#include <vector>
#include <algorithm>
int main ()
{
  std::ios::sync_with_stdio (false);
  std::cin.tie (nullptr);
  int t, n;
  std::vector<long long> a, b, bsum, cnt, add;
  std::cin >> t;
  while (t--)
  {
    std::cin >> n;
    a.resize (n); b.resize (n);
    for (int i = 0; i < n; ++i)
      std::cin >> a[i];
    for (int i = 0; i < n; ++i)
      std::cin >> b[i];

    bsum.assign (n + 1, 0);
    for (int i = 0; i < n; ++i)
      bsum[i + 1] = bsum[i] + b[i];
    
    cnt.assign (n + 1, 0);
    add.assign (n + 1, 0);

    for (int i = 0; i < n; ++i)
    {
      const int j = std::upper_bound (bsum.begin (), bsum.end (), bsum[i] + a[i]) - bsum.begin () - 1;
      cnt[j]--;
      add[j] += bsum[i] + a[i] - bsum[j];
    }

    for (int i = 1; i < n; ++i)
      cnt[i] += cnt[i - 1];
    for (int i = 0; i < n; ++i)
      cnt[i] = i + 1 + cnt[i];

    for (int i = 0; i < n; ++i)
      std::cout << cnt[i] * b[i] + add[i] << " \n"[i == n - 1];
  }
}
*/

/*
// https://codeforces.com/contest/1783/problem/C -- 1700
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
int main ()
{
  int t, n, m;
  std::vector<int> A, wins;
  std::vector<std::pair<int, int>> a;
  std::cin >> t;
  while (t--)
  {
    std::cin >> n >> m;
    a.resize (n);
    A.resize (n);
    wins.resize (n);
    for (int i = 0; i < n; ++i)
    {
      wins[i] = i + 1;
      a[i].second = i;
      std::cin >> a[i].first;
      A[i] = a[i].first;
    }
    std::sort (a.begin (), a.end ());

    std::set<int> was;
    for (int i = 0; i < n; ++i)
    {
      if (m - a[i].first >= 0)
      {
        m -= a[i].first;
        was.insert (a[i].second);
        wins[a[i].second]--;
      }
      else
        break;
    }
    const int my_wins = was.size ();
    int i_next = std::upper_bound (wins.begin (), wins.end (), my_wins) - wins.begin ();
    if (i_next == n)
    {
      std::cout << "1\n";
      continue;
    }  
    if (wins[i_next] == i_next + 1)
    {
      for (int i = 0; i < n; ++i)
      {
        if (wins[i] == i + 1 || wins[i] == my_wins || m + A[i] - A[i_next] < 0)
          continue;
        wins[i]++;
        wins[i_next]--;
        break;
      }
    }
    int ans = n - (std::upper_bound (wins.begin (), wins.end (), my_wins) - wins.begin ()) + 1;
    std::cout << ans << "\n";
  }
}
*/

/*
// https://codeforces.com/problemset/problem/1783/B -- 1100
#include <iostream>
#include <vector>
int main ()
{
  int t, n, l, r, is, js;
  std::cin >> t;
  while (t--)
  {
    std::cin >> n;
    std::vector<std::vector<int>> v (n, std::vector<int> (n));
    l = 1; r = n * n; is = 0, js = 0;
    for (int i = 0; i < n; ++i)
    {
      for (int j = 0; j < n; ++j)
      {
        v[i][is ? n - 1 - j : j] = js ? r-- : l++;
        js ^= 1;
      }
      is ^= 1;
    }
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j)
        std::cout << v[i][j] << " \n"[j == n - 1];
  }
}
*/

/*
// https://codeforces.com/problemset/problem/1783/A -- 800
#include <iostream>
#include <functional>
#include <map>
int main ()
{
  int t, n, a;
  std::cin >> t;
  while (t--)
  {
    std::map<int, int, std::greater<int>> m;
    std::cin >> n;
    for (int i = 0; i < n; ++i)
    {
      std::cin >> a;
      m[a]++;
    }
    if (m.size () == 1)
      std::cout << "NO";
    else
    {
      std::cout << "YES\n";
      std::cout << m.rbegin ()->first << " ";
      m.rbegin ()->second--;
      for (const auto &el : m)
        for (int i = 0; i < el.second; ++i)
          std::cout << el.first << " ";
    }
    std::cout << "\n";
  }
}
*/

/*
#include <iostream>
#include <string>
#include <cstdlib>
#include <assert.h>
#include <vector>
#include <list>

void clear_screen() {
#ifdef _WIN32
    std::system("cls");
#else
    // Assume POSIX
    std::system("clear");
#endif
}

enum class symbolType : int {
  Rock = 0,
  Paper,
  Scissors,
  Lizard,
  Spock,
  COUNT
};

std::string enum_to_text(const symbolType symbol) {
  assert (symbol != symbol_t::COUNT);
  switch (symbol) {
    case symbolType::Rock:     return "Rock";     break;
    case symbolType::Paper:    return "Paper";    break;
    case symbolType::Scissors: return "Scissors"; break;
    case symbolType::Lizard:   return "Lizard";   break;
    case symbolType::Spock:    return "Spock";    break;
    case symbolType::COUNT:    return "";         break;
  };
  return "";
}

class gameEngine {
private:
  std::vector<symbolType> symbols;
  std::vector<std::vector<bool>> winTable;
public:
  gameEngine() {

  }
};

struct rules_data_t {
  symbol_t    symbol;
  std::string action_name;
  rules_data_t (const symbol_t _symbol, const std::string &&_action_name)
    : symbol(_symbol), action_name(std::move (_action_name))
  {}
};

std::vector<rules_data_t> simple_rules = {
    {symbol_t::Paper   , "covers"},
    {symbol_t::Rock    , "crushes"},
    {symbol_t::Scissors, "cuts"}
};

std::vector<rules_data_t> tbd_rules = {
    {symbol_t::Scissors, "cuts"},
    {symbol_t::Paper   , "covers"},
    {symbol_t::Rock    , "crushes"},
    {symbol_t::Lizard  , "poisons"},
    {symbol_t::Spock   , "smashes"},
    {symbol_t::Scissors, "decapitates"},
    {symbol_t::Lizard  , "eats"},
    {symbol_t::Paper   , "disproves"},
    {symbol_t::Spock   , "vaporizes"},
    {symbol_t::Rock    , "crushes"}
};

namespace utils {
  bool check_atoi(std::string const &s) {
    char *p = nullptr;
    std::strtol (s.c_str (), &p, 10);
    return p == &s[s.size ()];
  }

  std::string getline_or_exit() {
    std::string s;
    if (!std::getline(std::cin, s)) {
      std::cerr << "Error stdin! Unexpected exit, sorry.";
      exit(0);
    }
    if (s == "exit") {
      exit(0);
    }
    return s;
  }
}

class Game_t
{
  const std::string game_name = "Paper - Rock - Scissors";
  unsigned int num_of_turns = 0; // ordered num of turns (0 if infinity game)
  unsigned int cur_turns = 0;    // current turn
  bool infinity_game = false;
  
  std::vector<std::vector<bool>> win_table;
  bool is_first_winer(const symbol_t first, const symbol_t second);
  void show_help() const;
  void show_info () const;
  void ask_num_of_turns();
public:
  void init();
};

bool is_first_winer(const symbol_t first, const symbol_t second) {
  return true;
}

void Game_t::show_help() const {
  clear_screen ();
  std::cout <<
    "\t'" << game_name << "'\n"
    "Instruction for menu:"
    " - input 'help' to see this instruction\n"
    " - input 'start' to quick start\n"
    " - input 'start <n>' to play n turns\n\n"
    "Instruction for turns:"
    " - input '[R]ock' to play Rock\n"
    " - input '[P]aper' to play Rock\n"
    " - input '[S]cissors' to play Rock\n\n"
    << std::flush;
}

void Game_t::show_info() const {
  clear_screen ();
  std::cout <<
    "'" << game_name << "' is a game for two players.\n"
    "Each turn each player simultaneously display a symbol:\n"

    "-     Rock (press R on keyboard)\n"
    "-    Paper (press P on keyboard)\n"
    "- Scissors (press S on keyboard)\n\n"
    "The winner of the turn is determined by the following schema:\n"
    "- paper beats (wraps) rock\n"
    "- rock beats (blunts) scissors\n"
    "- scissors beats (cuts) paper.\n\n";
}

void Game_t::ask_num_of_turns() {
  std::cout <<
    "Input how many turns you want to play (or press Enter for quick launch).\n"
    "Num of turns = ";
  std::string s = utils::getline_or_exit();
  if (s.empty()) {
    infinity_game = true;
  }
  else if (utils::check_atoi(s)) {
    num_of_turns = atoi(s.data());
  }
  else {
    infinity_game = true;
    std::cout << "Warning: incorrect input, the game will continue until you enter 'exit'.\n";
  }
}

void Game_t::init() {
  std::cout << "\t" << game_name << "\n";
  show_help ();

  ask_num_of_turns();
}

int main()
{
  Game_t game;
  game.init();
}
*/
/*
#include <iostream>
#include <vector>
#include <thread>
#include <algorithm>
#include <mutex>
bool isPolindrom (long long i)
{
  std::vector<int> v; v.reserve (18);
  while (i > 0)
    v.push_back (i % 10), i /= 10;
  const int n = v.size ();
  for (int j = 0; j < n; ++j)
    if (v[j] != v[n - 1 - j])
      return false;
  return true;
}
int main ()
{
  std::cout << "The number of concurrent threads is " << std::thread::hardware_concurrency () << "\n";

//const long long max_dig = 1000000000000000000;
  const long long max_dig = 1000000000000000000;
  std::vector<long long> ans;

  if (0)
    {
      for (long long i = 1; i * i < max_dig; ++i)
        {
          if (isPolindrom (i) && isPolindrom (i * i))
            ans.push_back (i * i);
        }
      for (int i = 0; i < ans.size (); ++i)
        std::cout << i + 1 << " " << ans[i] << "\n";
      return 0;
    }


  const int threads_num = std::thread::hardware_concurrency () / 4;
  std::vector<std::thread> threads;
  threads.reserve (threads_num);
  std::mutex ans_mutex;
  for (int thread_num = 0; thread_num < threads_num; ++thread_num)
    {
      threads.emplace_back (std::thread ([&ans, thread_num, threads_num, &ans_mutex, max_dig]() {
          for (long long i = 1 + thread_num; i * i < max_dig; i += threads_num)
            {
              if (isPolindrom (i) && isPolindrom (i * i))
                {
                  ans_mutex.lock ();
                  ans.push_back (i * i);
                  //std::cout << i * i << ", ";
                  ans_mutex.unlock ();
                }
            } 
        }));
    }
  for (int thread_num = 0; thread_num < threads_num; ++thread_num)
    threads[thread_num].join ();

  std::sort (ans.begin (), ans.end ());
  for (int i = 0; i < ans.size (); ++i)
    std::cout << i + 1 << " " << ans[i] << "\n";
}
*/
/*
#include <iostream>
int main ()
{
  int t, n, k;
  std::cin >> t;
  while (t--)
    {
      std::cin >> n >> k;
      if (k == n - 1)
        {
          if (n <= 4)
            {
              std::cout << "-1\n";
            }
          else
            {
              std::cout << "0 2\n1" << " " << n - 3 << "\n" << n - 1 << " " << n - 2 << "\n";
              for (int i = 3; i < n / 2; ++i)
                std::cout << i << " " << n - i - 1 << "\n";
            }
        }
      else if (k == 0)
        {
          for (int i = 0; i < n / 2; ++i)
            std::cout << i << " " << n - i - 1 << "\n";
        }
      else
        {
          for (int i = 1; i < n / 2; ++i)
            {
              if (i == k || i == n - k - 1)
                {
                  std::cerr << k << " " << n - 1 << "\n";
                  std::cerr << n - k - 1 << " " << 0 << "\n";
                }
              else
                std::cout << i << " " << n - i - 1 << "\n";
            }
        }
    }
}
*/
/*
// https://codeforces.com/contest/764/problem/C -- 1600
#include <iostream>
#include <vector>
#include <set>

int n;
std::vector<std::vector<int>> v;
std::vector<int> c;
bool check (const int a, const int prev)
{
  for (int i : v[a])
    {
      if (i == prev)
        continue;
      if (c[a] != c[i] || !check (i, a))
        return false;
    }
  return true;
}
bool check2 (const int a)
{
  for (int i : v[a])
    {
      if (!check (i, a))
        return false;
    }
  return true;
}
int main ()
{
  std::cin >> n;
  v.resize (n);
  for (int i = 1; i < n; ++i)
    {
      int a, b;
      std::cin >> a >> b;
      a--; b--;
      v[a].push_back (b);
      v[b].push_back (a);
    }
  c.resize (n);
  for (int i = 0; i < n; ++i)
    std::cin >> c[i];
  for (int i = 0; i < n; ++i)
    {
      for (int j : v[i])
        if (c[i] != c[j])
          {
            if (check2 (i))
              std::cout << "YES\n" << i + 1 << "\n";
            else if (check2 (j))
              std::cout << "YES\n" << j + 1 << "\n";
            else
              std::cout << "NO\n";
            return 0;
          }
    }
  std::cout << "YES\n1\n";
}
*/
/*
//https://codeforces.com/problemset/problem/1629/B --800
#include <iostream>
#include <vector>
int main ()
{
  int t, l, r, k;
  std::cin >> t;
  while (t--)
    {
      std::cin >> l >> r >> k;
      if (l == r)
        std::cout << (l == 1 ? "NO\n" : "YES\n");
      else
        std::cout << ((r - l + 1) / 2 + (r % 2 == 1 && l % 2 == 1? 1 : 0) <= k ? "YES\n" : "NO\n");
    }
}
*/
/*
//https://codeforces.com/problemset/problem/1629/A --800
#include <iostream>
#include <vector>
#include <algorithm>
int main ()
{
  int t, n, k;
  struct T { int a, b; };
  std::vector<T> v;
  std::cin >> t;
  while (t--)
    {
      std::cin >> n >> k;
      v.resize (n);
      for (int i = 0; i < n; ++i)
        std::cin >> v[i].a;
      for (int i = 0; i < n; ++i)
        std::cin >> v[i].b;
      std::sort (v.begin (), v.end (), [](const T &a, const T &b) { return a.a < b.a; });
      for (int i = 0; i < n && k >= v[i].a; ++i)
        k += v[i].b;
      std::cout << k << "\n";
    }
}
*/
/*
//https://codeforces.com/problemset/problem/1628/B --1700
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
int main ()
{
  int t, n;
  std::vector<std::string> v;
  std::cin >> t;
  while (t--)
    {
      std::cin >> n;
      v.resize (n);
      bool ok = false;
      for (int i = 0; i < n; ++i)
        {
          std::cin >> v[i];
          if (ok) continue;
          ok = true;
          for (int j = 0; j <= v[i].size () / 2; ++j)
            if (v[i][j] != v[i][v[i].size () - 1 - j])
              {
                ok = false;
                break;
              }
        }
      if (!ok)
        {
          std::unordered_set<char> m1;
          std::unordered_map<char, std::unordered_set<char>> m2, m3d, m3_;
          std::unordered_map<char, std::unordered_set<std::string>> m3;
          for (int i = 0; i < n; ++i)
            {
              if (v[i].size () == 1)
                {
                  if (   (m1.count (v[i][0]))
                      || (m2.count (v[i][0]))
                      || (m3d.count (v[i][0])))
                    {
                      ok = true;
                      break;
                    }
                  m1.insert (v[i][0]);
                }
              else if (v[i].size () == 2)
                {
                  if (   (m1.count (v[i][1]))
                      || (m2.count (v[i][1]) && m2[v[i][1]].count (v[i][0]))
                      || (m3_.count (v[i][1]) && m3_[v[i][1]].count (v[i][0])))
                    {
                      ok = true;
                      break;
                    }
                  m2[v[i][0]].insert (v[i][1]);
                }
              else
                {
                  std::string ss = v[i].substr (1, 1) + v[i][0];
                  if (   (m1.count (v[i][2]) && v[i][0] == v[i][1])
                      || (m2.count (v[i][2]) && m2[v[i][2]].count (v[i][1]))
                      || (m3.count (v[i][2]) && m3[v[i][2]].count (ss)))
                    {
                      ok = true;
                        break;
                    }
                  m3[v[i][0]].insert (v[i].substr (1));
                  m3_[v[i][0]].insert (v[i][1]);
                  if (v[i][0] == v[i][1])
                    m3d[v[i][0]].insert (v[i][1]);
                }
            }
        }
      std::cout << (ok ? "YES" : "NO") << "\n";
    }
}
*/
/*
//https://codeforces.com/problemset/problem/1628/A --1400
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
int main ()
{
  int t, n, a;
  std::vector<std::queue<int>> v;
  std::vector<int> ans;
  std::cin >> t;
  while (t--)
    {
      std::cin >> n;
      ans.clear ();
      v.clear (); v.resize (n + 1);
      for (int i = 0; i < n; ++i)
        std::cin >> a, v[a].push (i);
      int mx = -1;
      while (mx < n - 1)
        {
          int i = 0;
          for (; i <= n; ++i)
            if (!v[i].empty ())
              {
                a = v[i].front (); v[i].pop ();
                mx = std::max (mx, a);
              }
            else
              {
                if (i == 0) ++mx;
                break;
              }
          for (int j = 0; j < i; ++j)
            while (!v[j].empty () && v[j].front () < mx)
              v[j].pop ();
          ans.push_back (i);
        }
      std::cout << ans.size () << "\n";
      for (int el : ans)
        std::cout << el << " ";
      std::cout << "\n";
    }
}
*/
/*
//https://codeforces.com/problemset/problem/1627/D --1900
#include <iostream>
#include <vector>
const int inf = 1000000;
int gcd (int a, int b)
{
  while (a && b) {
    if (a > b)
      a %= b;
    else
      b %= a;
  }
  return a + b;
}
int main ()
{
  std::vector<int> a (inf + 1, 0);
  int n, b, ans = 0;
  std::cin >> n;
  for (int i = 0; i < n; ++i)
    std::cin >> b, a[b] = 1;
  for (int i = 1; i <= inf; ++i)
    if (!a[i])
      {
        int j = i * 2;
        while (j <= inf && !a[j])
          j += i;
        if (j > inf)
          continue;
        int tGCD = j;
        for (j += i; j <= inf; j += i)
          if (a[j])
            {
              tGCD = gcd (j, tGCD);
              if (tGCD == i)
                break;
            }
        if (tGCD == i)
          ++ans;
      }
  std::cout << ans << "\n";
}
*/
/*
//https://codeforces.com/problemset/problem/1627/C --1400
#include <iostream>
#include <vector>
#include <unordered_map>
int main ()
{
  int t, n, a, b;
  std::cin >> t;
  std::vector<std::vector<int>> v;
  std::unordered_map<long long, int> keys;
  std::vector<int> ans;
  while (t--)
    {
      std::cin >> n;
      keys.clear ();
      v.clear (); v.resize (n + 1);
      bool ok = true;
      for (int i = 1; i < n; ++i)
        {
          std::cin >> a >> b;
          if (v[a].size () > 1 || v[b].size () > 1)
            ok = false;
          if (!ok)
            continue;
          v[a].push_back (b);
          v[b].push_back (a);
          keys[1LL * a * 100001 + b] = i;
          keys[1LL * b * 100001 + a] = i;
        }
      if (!ok)
        {
          std::cout << "-1\n";
          continue;
        }
      int cur = 0;
      for (int i = 1; i < n; ++i)
        if (v[i].size () == 1)
          {
            cur = i;
            break;
          }
      ans.resize (n + 1);
      int next = v[cur][0];
      std::vector<int> val = {2, 3};
      int i = 0;
      while (true)
        {
          ans[keys[1LL * cur * 100001 + next]] = val[i];
          i = (i + 1) % 2;
          if (v[next].size () == 1)
            break;
          if (v[next][0] != cur)
            {
              cur = next;
              next = v[next][0];
            }
          else
            {
              cur = next;
              next = v[next][1];
            }
        }
      for (int i = 1; i < n; ++i)
        std::cout << ans[i] << " ";
      std::cout << "\n";
    }
}
*/
/*
//https://codeforces.com/problemset/problem/1627/B --1300
#include <iostream>
#include <vector>
#include <algorithm>
int main ()
{
  int t, n, m;
  std::vector<int> v;
  std::cin >> t;
  while (t--)
    {
      std::cin >> n >> m;
      v.clear (); v.reserve (n * m);
      for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
          v.push_back (
            std::max (
              std::max (
                (i - 1) + (j - 1),
                (i - 1) + (m - j)),
              std::max (
                (n - i) + (j - 1),
                (n - i) + (m - j)))
            );
      std::sort (v.begin (), v.end ());
      for (int el : v)
        std::cout << el << " ";
      std::cout << "\n";
    }
}
*/
/*
//https://codeforces.com/problemset/problem/1627/A --800
#include <iostream>
#include <string>
#include <vector>
int main ()
{
  int t, n, m, r, c, ans;
  std::cin >> t;
  std::vector<std::string> v;
  while (t--)
    {
      std::cin >> n >> m >> r >> c;
      --r; --c;
      v.resize (n);
      for (int i = 0; i < n; ++i)
        std::cin >> v[i];
      if (v[r][c] == 'B')
        ans = 0;
      else
        {
          bool ok = false;
          for (int i = 0; i < n; ++i)
            if (v[i][c] == 'B')
              { ok = true; break; }
          for (int i = 0; i < m; ++i)
            if (v[r][i] == 'B')
              { ok = true; break; }
          if (ok)
            ans = 1;
          else
            {
              for (int i = 0; i < n && !ok; ++i)
                for (int j=0;j<m;++j)
                  if (v[i][j] == 'B')
                    { ok = true; break; }
              if (ok)
                ans = 2;
              else
                ans = -1;
            }
        }
      std::cout << ans << "\n";
    }
}
*/
/*
//https://codeforces.com/problemset/problem/1626/C --1700
#define IOS std::ios::sync_with_stdio (0), std::cin.tie (0);
#include <iostream>
#include <vector>
#include <algorithm>
int main ()
{
  IOS
  int t, n;
  long long x;
  std::vector<int> k, h;
  std::cin >> t;
  while (t--)
    {
      x = 0;
      std::cin >> n;
      k.resize (n);
      for (int i = 0; i < n; ++i)
        std::cin >> k[i];
      h.resize (n);
      for (int i = 0; i < n; ++i)
        std::cin >> h[i];
      std::vector<std::pair<int, int>> v; v.reserve (n * 2);
      for (int i = 0; i < n; ++i)
        v.push_back ({k[i] - h[i],  1}),
        v.push_back ({k[i]       , -1});
      std::sort (v.begin (), v.end ());
      int sum = v[0].second, start = v[0].first;
      for (int i = 1; i < v.size (); ++i)
        {
          sum += v[i].second;
          if (sum == 0)
            {
              int end = v[i].first;
              x += 1LL * (end - start + 1) * (end - start) / 2;
              if (i < v.size () - 1)
                start = v[i + 1].first;
            }
        }
      std::cout << x << "\n";
    }
}
*/

/*
// https://codeforces.com/problemset/problem/1626/B --1100
#include <iostream>
#include <string>
#include <algorithm>
int main ()
{
  IOS
  int t, n;
  std::string s, ans, tmp;
  std::cin >> t;
  while (t--)
    {
      std::cin >> s; n = s.size ();
      ans = "";
      for (int i = n - 1; i > 0; --i)
        {
          const int val = (int)(s[i] - '0') + (int)(s[i - 1] - '0');
          if (val >= 10)
            {
              ans = (i > 1 ? s.substr (0, i - 1) : "")
                  + std::to_string (val)
                  + (i < n - 1 ? s.substr (i + 1) : "");
              break;
            }
        }
      if (ans.empty ())
        {
          int i = 1;
          const int val = (int)(s[i] - '0') + (int)(s[i - 1] - '0');
          ans = (i > 1 ? s.substr (0, i - 1) : "")
              + std::to_string (val)
              + (i < n - 1 ? s.substr (i + 1) : "");
        }
      std::cout << ans << "\n";
    }
}
*/
/*
// https://codeforces.com/problemset/problem/1626/A --800
#include <iostream>
#include <string>
#include <vector>
int main ()
{
  int t;
  std::cin >> t;
  std::vector<int> v (26);
  while (t--)
    {
      std::string s, ans;
      std::cin >> s;
      std::fill (v.begin (), v.end (), 0);
      for (const char c : s)
        v[c - 'a']++;
      for (int i = 0; i < v.size (); ++i)
        if (v[i] == 2)
          ans += (char)('a' + i);
      ans += ans;
      for (int i = 0; i < v.size (); ++i)
        if (v[i] == 1)
          ans += (char)('a' + i);
      std::cout << ans << "\n";
    }
}
*/
/*
//https://codeforces.com/problemset/problem/1625/C --1700
#include <iostream>
#include <vector>
#include <algorithm>
const int inf = 1000000000;
int main ()
{
  int n, l, k;
  std::cin >> n >> l >> k;
  std::vector<int> d (n + 1), a (n);
  for (int i = 0; i < n; ++i)
    std::cin >> d[i];
  d[n] = l;
  for (int i = 0; i < n; ++i)
    std::cin >> a[i];

  std::vector<std::vector<int>> dp (n + 1, std::vector<int> (k + 1, inf));
  dp[0][0] = 0;

  for (int i = 0; i < n; ++i)
    for (int j = 0; j <= k; ++j)
      for (int pos = i + 1; pos <= n; ++pos)
        {
          const int h = j + pos - i - 1;
          if (h > k)
            continue;
          dp[pos][h] = std::min (dp[pos][h], dp[i][j] + a[i] * (d[pos] - d[i]));
        }
  int ans = inf;
  for (int i = 0; i <= k; ++i)
    ans = std::min (ans, dp[n][i]);
  std::cout << ans;
}
*/
/*//https://codeforces.com/problemset/problem/1625/B --1100
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
int main ()
{
  int t, n;
  std::vector<int> a;
  std::unordered_map<int, std::vector<int>> v (150000);
  std::cin >> t;
  while (t--)
    {
      std::cin >> n;
      a.resize (n);
      v.clear ();
      for (int i = 0; i < n; ++i)
        {
          std::cin >> a[i];
          v[a[i] - 1].push_back (i);
        }
      int ans = -1;
      for (const auto el : v)
        {
          const auto &w = v[el.first];
          for (int i = 1; i < w.size (); ++i)
            ans = std::max (n - w[i] + w[i - 1], ans);
        }
      std::cout << ans << "\n";
    }
}
*/
/*
//https://codeforces.com/problemset/problem/1625/A --800
#include <iostream>
#include <vector>
int main ()
{
  int t, n, l, a;
  std::cin >> t;
  std::vector<int> v;
  while (t--)
    {
      std::cin >> n >> l;
      v.clear (); v.resize (l);
      for (int i = 0; i < n; ++i)
        {
          int m = 0;
          std::cin >> a;
          while (a > 0)
            {
              if (a % 2 == 1)
                v[m]++;
              a /= 2;
              ++m;
            }
        }
      int ans = 0;
      for (int i = l - 1; i >= 0; --i)
        {
          if (n - v[i] < v[i])
            ans += 1;
          ans *= 2;
        }
      ans /= 2;
      std::cout << ans << "\n";
    }
}
*/



/*
//https://codeforces.com/problemset/problem/1793/D --1800
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
int main ()
{
	int n;
	std::cin >> n;
	std::vector<int> p (n + 1), q (n + 1);
	std::map<int, int> mq, mp;	for (int i = 1; i <= n; ++i)
		std::cin >> p[i], mp[p[i]] = i;
	for (int i = 1; i <= n; ++i)
		std::cin >> q[i], mq[q[i]] = i;

	long long ans = 1;
	int l_in = n, r_in = -1;
	auto find_cnt = [&l_in, &r_in] (const int l, const int r) -> long long
	{
		if (l > r)
			return 0;

		if (r_in == -1)
		{
			static std::vector<long long> b2 (1, 1);
			while (b2.size () < r - l + 1)
			{
				const long long m = b2.size () + 1;
				b2.push_back (m * m - b2.back ());
			}
			return b2[r - l];
		}

		if (l_in < l || r_in > r)
			return 0;

		const long long l_cnt = l_in - l + 1;
		const long long r_cnt = r - r_in + 1;
		return l_cnt * r_cnt;
	};
	for (int i = 1; i <= n; ++i)
	{
		const int l_ex = std::min (mp[i], mq[i]), r_ex = std::max (mp[i], mq[i]);
		const auto add1 = find_cnt (1       , l_ex - 1);
		const auto add2 = find_cnt (l_ex + 1, r_ex - 1);
		const auto add3 = find_cnt (r_ex + 1, n       );
		ans += add1 + add2 + add3;
		l_in = std::min (l_in, l_ex);
		r_in = std::max (r_in, r_ex);
	}
	std::cout << ans << std::endl;
}
*/

/*
//https://codeforces.com/problemset/problem/1793/C --1200
#include <iostream>
#include <vector>
int main ()
{
	int t, n;
	std::vector<int> a;
	std::cin >> t;
	while (t--)
	{
		std::cin >> n;
		a.resize (n);
		for (int i = 0; i < n; ++i)
			std::cin >> a[i];
		int l = 1, r = n, il = 0, ir = n - 1;
		while (il < ir)
		{
			if (a[il] == l)
				++l, ++il;
			else if (a[il] == r)
				--r, ++il;
			else if (a[ir] == l)
				++l, --ir;
			else if (a[ir] == r)
				--r, --ir;
			else
				break;
		}
		if (il == ir)
			std::cout << "-1\n";
		else
			std::cout << il + 1 << " " << ir + 1 << std::endl;
	}
}
*/

/*
//https://codeforces.com/problemset/problem/1793/B --1100
#include <iostream>
int main ()
{
	int t, x, y;
	std::cin >> t;
	while (t--)
	{
		std::cin >> x >> y;
		std::cout << (x - y) * 2 << std::endl;
		for (int i = x; i >= y; --i)
			std::cout << i << " ";
		for (int i = y + 1; i < x; ++i)
			std::cout << i << " \n"[i == x - 1];
	}
}
*/

/*
//https://codeforces.com/problemset/problem/1793/A --800
#include <iostream>
int main ()
{
	long long t, n, m, a, b;
	std::cin >> t;
	while (t--)
	{
		std::cin >> a >> b >> n >> m;
		const long long c = n / (m + 1) * m;
		const long long add = n % (m + 1);
		if (a * m >= b * (m + 1))
			std::cout << b * n << std::endl;
		else
			std::cout << c * a + add * (a < b ? a : b) << std::endl;
	}
}
*/

/*
//https://codeforces.com/contest/1795/problem/B --900
#include <iostream>
#include <vector>
int main ()
{
	constexpr int inf = 50 + 1;
	int t, n, k, l, r;
	std::cin >> t;
	std::vector<int> a;
	while (t--)
	{
		std::cin >> n >> k;
		a.clear ();
		a.resize (inf, 0);
		for (int i = 0; i < n; ++i)
		{
			std::cin >> l >> r;
			if (l > k || k > r)
				continue;
			for (int i = l; i <= r; ++i)
				a[i]++;
		}
		int ok = true;
		for (int i = 1; i < inf; ++i)
			if (i != k && a[i] >= a[k])
			{
				ok = false;
				break;
			}
		std::cout << (ok ? "YES" : "NO") << "\n";
	}
}
*/

/*
//https://codeforces.com/contest/1795/problem/A -- 800
#include <iostream>
#include <vector>
int main ()
{
	int t, n, m;
	std::cin >> t;
	std::vector<char> v;
	while (t--)
	{
		std::cin >> n >> m;
		v.resize (n + m);
		for (int i = 0; i < n; ++i)
			std::cin >> v[i];
		for (int i = n + m - 1; i >= n; --i)
			std::cin >> v[i];
		int was = 0;
		for (int i = 0; i < n + m - 1; ++i)
			if (v[i] == v[i + 1])
			{
				++was;
				if (was > 1)
					break;
			}
		std::cout << (was > 1 ? "NO" : "YES") << "\n";
	}
}
*/

/*
//https://contest.yandex.ru/contest/27049/problems/E/
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
int main ()
{
	int userLimit, serviceLimit, duration, time, userId, user_cnt, service_cnt;
	std::cin >> userLimit >> serviceLimit >> duration;
	std::vector<int> full_log;
	std::map<int, std::vector<int>> users_log;
	while (true)
		{
			std::cin >> time;
			if (time < 0) break;
			std::cin >> userId;
			if (!users_log.count (userId))
				users_log[userId].push_back (-duration - 1);

			auto users_it = std::lower_bound (users_log[userId].begin (), users_log[userId].end (), time - duration);
			if (users_it == users_log[userId].end ())
				user_cnt = 0;
			else
				user_cnt = users_log[userId].size () - (users_it - users_log[userId].begin ());
			if (user_cnt >= userLimit)
				{
					std::cout << "429\n";
					fflush(stdout);
					continue;
				}

			auto service_it = std::lower_bound (full_log.begin (), full_log.end (), time - duration);
			if (service_it == full_log.end ())
				service_cnt = 0;
			else
				service_cnt = full_log.size () - (service_it - full_log.begin ());
			if (service_cnt >= serviceLimit)
				{
					std::cout << "503\n";
					fflush(stdout);
					continue;
				}

			std::cout << "200\n";
			users_log[userId].push_back (time);
			full_log.push_back (time);
			fflush(stdout);
		}
}
*/

/*
//https://contest.yandex.ru/contest/27049/problems/B/
#include <iostream>
#include <string>
void cin_date (int &y, int &m, int &d)
{
	char q1, q2;
	std::cin >> y >> q1 >> m >> q2 >> d;
}
int main ()
{
	std::string interval_type, date_start_str, date_end_str;
	int y1,y2,m1,m2,d1,d2;
	std::cin >> interval_type;
	cin_date (y1, m1, d1);
	cin_date (y2, m2, d2);

	// struct tm date_start = { 0 }, date_end = { 0 };
	// sscanf (date_start_str.c_str (), "%04d-%02d-%02d", &date_start.tm_year, &date_start.tm_mon, &date_start.tm_mday);
	// sscanf (date_end_str.c_str ()  , "%04d-%02d-%02d", &date_end.tm_year  , &date_end.tm_mon  , &date_end.tm_mday);

	tm date_start;
	date_start.tm_year = y1;
	date_start.tm_mon = m1;
	date_start.tm_mday = d1;

	time_t time = mktime (&date_start);
	time += time(0) + 24*60*60;
	tm now;
	localtime_s(&now, &time);

	std::cout << date_start_str << "\n" << (now.tm_year + 1900) << '-'
				 << (now.tm_mon + 1) << '-'
				 <<  now.tm_mday
				 << "\n";

	int intervals_cnt = 0;
	//switch (interval_type[0])
	//	{
	//		case 'W':
	//			//while (date_start != date_end)
	//				{
	//
	//				}
	//	}
}
*/

/*
//1512G	--1700
#include <iostream>
#include <vector>
int main ()
{
	const int inf = 10000000;
	std::vector<int> v (inf + 7, 1), d(inf + 7, -1);
	for (int i = 2; i <= inf; ++i)
		for (int j = i; j <= inf; j += i)
			{
				if (!v[j])	continue;
				if (v[j] + i > inf) v[j] = 0;
				else            	  v[j] += i;
			}
	for (int i = inf; i > 0; --i)
		d[v[i]] = i;

	int t, n, c;
	std::cin >> t;
	while (t--)
		{
			std::cin >> c;
			std::cout << d[c] << "\n";
		}
}
*/

/*
//1512E	--1600
#include <iostream>
#include <unordered_set>
// THNX MikeMirzayanov
int low (const int k)
{
	return k * (k + 1) / 2;
}
int high (const int n, const int k)
{
	return k * (2 * n - k + 1) / 2;
}
int main ()
{
	int t, n, l, r, s;
	std::cin >> t;
	while (t--)
		{
			std::cin >> n >> l >> r >> s;
			int k = r - l + 1;
			std::unordered_set<int> ans;
			for (int i = n; i > 0; --i)
				{
					if (k > 0 && low (k - 1) <= s - i && s <= high (i, k))
						{
							ans.insert (i);
							--k;
							s -= i;
						}
				}
			if (s == 0)
				{
					for (int i = 1, j = 1; i <= n; ++i)
						{
							if (i == l)
								{
									--i;
									for (const int el : ans)
										{
											std::cout << el << " ";
											++i;
										}
								}
							else
								{
									while (ans.count (j))
										++j;
									std::cout << j++ << " ";
								}
						}
				}
			else
				{
					std::cout << "-1";
				}
			std::cout << "\n";
		}
}
*/

/*
//1509B	--1100
#include <iostream>
#include <string>
int main ()
{
	int t, n, T, M;
	std::cin >> t;
	std::string s;
	while (t--)
		{
			std::cin >> n >> s;
			bool ok = true;

			T = 0, M = 0;
			for (int i = 0;i < n; ++i)
				{
					if (s[i] == 'T') ++T; else ++M;
					if (T < M) { ok = false; break; }
				}
			if (T != M * 2) ok = false;

			if (ok)
				{
					T = 0, M = 0;
					for (int i = n - 1; i >= 0; --i)
						{
							if (s[i] == 'T') ++T; else ++M;
							if (T < M) { ok = false; break; }
						}
				}
			std::cout << (ok ? "YES\n" : "NO\n");
		}
}
*/

/*
//1503B --1700
#include <iostream>
#include <queue>
int main ()
{
	int n, a, b, qi, t;
	std::cin >> n;
	std::queue<std::pair<int, int>> q[2];
	for (int i = 0;i < n; ++i)
		for (int j = 0; j < n; ++j)
			q[(i + j) % 2].push ({i + 1, j + 1});
	t = n * n;
	while (t--)
		{
			std::cin >> a;
			if (a == 1)
				{
					if (!q[1].empty ())
						{
							b = 2;
							qi = 1;
						}
					else
						{
							b = 3;
							qi = 0;
						}
				}
			else if (a == 2)
				{
					if (!q[0].empty ())
						{
							b = 1;
							qi = 0;
						}
					else
						{
							b = 3;
							qi = 1;
						}
				}
			else
				{
					if (!q[0].empty ())
						{
							b = 1;
							qi = 0;
						}
					else
						{
							b = 2;
							qi = 1;
						}
				}
			std::pair<int, int> el = q[qi].front ();
			q[qi].pop ();
			std::cout << b << " " << el.first << " " << el.second << "\n";
			std::cout.flush();
		}
}
*/

/*
//1503A	--1600
//THANX 1-gon
#include <iostream>
#include <string>
int main ()
{
	int t, n;
	std::string s;
	std::cin >> t;
	while (t--)
		{
			std::cin >> n >> s;
			int n1 = 0, k = 0;
			for (int i = 0; i < n; ++i)
				n1 += (s[i] == '1');
			if (n1 % 2 == 1 || s[0] == '0' || s.back () == '0')
				{
					std::cout << "NO\n";
					continue;
				}
			std::cout << "YES\n";
			std::string s1, s2;
			bool flip = false;
			for (int i=0;i<n;++i)
				if (s[i] == '1')
					{
						s1.push_back (2 * k < n1 ? '(' : ')');
						s2.push_back (s1.back ());
						++k;
					}
				else
					{
						s1.push_back (flip ? '(' : ')');
						s2.push_back (flip ? ')' : '(');
						flip = !flip;
					}
			std::cout << s1 << "\n" << s2 << "\n";
		}
}
*/

/*
//1509A	--800
#include <iostream>
#include <vector>
int main ()
{
	int t, n;
	std::cin >> t;
	while (t--)
		{
			std::cin >> n;
			std::vector<int> a (n);
			for (int i = 0; i < n; ++i)
				std::cin >> a[i];
			for (int j = 0; j < 2; ++j)
				for (int i = 0; i < n; ++i)
					if (a[i] % 2 == j)
						std::cout << a[i] << " ";
			std::cout << "\n";
		}
}
*/

/*
//1513A	--800
#include <iostream>
int main ()
{
	int t, n, k;
	std::cin >> t;
	while (t--)
		{
			std::cin >> n >> k;
			if ((n - 1) / 2 < k)
				{
					std::cout << "-1\n";
					continue;
				}
			std::cout << "1 ";
			int c = 1;
			for (int i = 1; i <= k; ++i)
				{
					std::cout << i * 2 + 1 << " " << i * 2 << " ";
					c += 2;
				}
			while (c < n)
				std::cout << ++c << " ";
			std::cout << "\n";
		}
}
*/

/*
//1510K	--1200
#include <iostream>
#include <vector>
#include <algorithm>
int main ()
{
	int n;
	std::cin >> n;
	std::vector<int> p (n * 2), a (n * 2), sorted (n * 2);
	for (int i = 0; i < n * 2; ++i)
		std::cin >> p[i],
		//p[i] = (i % 2 ? i : i + 2),
		a[i] = p[i],
		sorted[i] = i + 1;
	int ans = 0, lans = 0;
	bool ok = false;
	do
		{
			if (a == sorted)
				{
					ans = std::min (lans, n * 2 - lans);
					ok = true;
					break;
				}
			if (lans % 2)
				{
					for (int i = 0; i < n; ++i)
						std::swap (a[i * 2], a[i * 2 + 1]);
				}
			else
				{
					for (int i = 0; i < n; ++i)
						std::swap (a[i], a[n + i]);
				}
			++lans;
		}
	while (a != p);
	a = p;
	lans = 0;
	do
		{
			if (a == sorted)
				{
					if (ok)
						ans = std::min (ans, std::min (lans, n * 2 - lans));
					else
						ans = std::min (lans, n * 2 - lans);
					ok = true;
					break;
				}
			if (lans % 2 == 0)
				{
					for (int i = 0; i < n; ++i)
						std::swap (a[i * 2], a[i * 2 + 1]);
				}
			else
				{
					for (int i = 0; i < n; ++i)
						std::swap (a[i], a[n + i]);
				}
			++lans;
		}
	while (a != p);
	if (ok)	std::cout << ans << "\n";
	else    std::cout << "-1\n";
}
*/

/*
//1504B	--1200
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
int main ()
{
	int t, n;
	std::string a, b;
	std::cin >> t;
	while (t--)
		{
			std::vector<int> va (2, 0), vb (2, 0);
			int s = 0;
			std::cin >> n >> a >> b;
			if (a == b)
				{
					std::cout << "YES\n";
					continue;
				}
			bool ok = true;
			for (int i = 0; i < n && ok; ++i)
				{
					va[a[i] - '0']++; vb[b[i] - '0']++;
					if (va[0] == va[1] && vb[0] == vb[1])
						{
							std::vector<int> eq (2, 0);
							for (int j = s; j <= i; ++j)
								eq[a[j] == b[j]]++;
							if (eq[0] && eq[1])
								ok = false;
							s = i + 1;
							std::fill (va.begin (), va.end (), 0);
							std::fill (vb.begin (), vb.end (), 0);
						}
				}
			if (ok && s != n)
				{
					for (int i = s; i < n && ok; ++i)
						if (a[i] != b[i])
							ok = false;
				}
			std::cout << (ok ? "YES\n" : "NO\n");
		}
}
*/

/*
//1504A --800
#include <iostream>
#include <string>
int main ()
{
	int t;
	std::string s;
	std::cin >> t;
	while (t--)
		{
			std::cin >> s;
			bool ok = false;
			for (const char q : s)
				if (q != 'a')
					ok = true;
			if (!ok)
				{
					std::cout << "NO\n";
					continue;
				}
			for (int i = 0;; ++i)
				{
					if (s[i] != 'a')
						{
							std::cout << "YES\n" << s.substr (0, s.size () - i) << 'a' << s.substr (s.size () - i, i) << "\n";
							break;
						}
				}
		}
}
*/

/*
DOESN'T ENDED
//1511E
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <functional>
const int inf = 998244353;
int n, m;
std::vector<std::string> tb;
std::vector<std::vector<int>> was;
long long ans = 0;
void make (const int X, const int Y)
{
	std::vector<std::vector<int>> v;
	std::set<std::pair<int, int>> s;
	std::queue<std::pair<int, int>> qx, qy;
	s.insert ({X, Y});
	long long cnt = 0;
	while (!s.empty ())
		{
			cnt++;
			auto &el = *s.begin ();
			int x = el.first, y = el.second;
			s.erase (s.begin ());

			if (x < n - 1 && tb[x + 1][y] == 'o')
				s.insert ({x + 1, y});
			if (y < m - 1 && tb[x][y + 1] == 'o')
				s.insert ({x, y + 1});

			if (x == 0 || tb[x - 1][y] != 'o')
				qx.push ({x, y});
			if (y == 0 || tb[x][y - 1] != 'o')
				qx.push ({x, y});
		}
	while (!qx.empty ())
		{

		}
}
int main ()
{
	std::cin >> n >> m;
	tb.resize (n);
	was.resize (n);
	long long w = 0;
	for (int i = 0; i < n; ++i)
		{
			std::cin >> tb[i];
			for (int j = 0; j < m; ++j)
				if (tb[i][j] == 'o')
					++w;
			was[i].resize (m, 0);
		}
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			{
				if (tb[i][j] == 'o' && !was[i][j])
					make (i, j);
			}
	std::cout << ans << "\n";
}
*/

/*
//1511D
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <functional>
int main ()
{
	int n, k;
	std::cin >> n >> k;
	std::string s;
	while (s.size () < n)
		{
			for (int i = 0; i < k; ++i)
				{
					s += (i + 'a');
					if (s.size () == n) break;
					for (int j=i+1;j<k;++j)
						{
							s += (i + 'a');
							if (s.size () == n) break;
							s += (j + 'a');
							if (s.size () == n) break;
						}
					if (s.size () == n) break;
				}
		}
	std::cout << s << "\n";
}
*/

/*
//1511C
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <functional>
int main ()
{
	int n, q, t;
	std::cin >> n >> q;
	std::vector<int> a (n), v (51, -1);
	for (int i=0; i < n; ++i)
		std::cin >> a[i];
	for (int i = n - 1; i >= 0; --i)
		v[a[i]] = i;
	while (q--)
		{
			std::cin >> t;
			int pos = v[t];
			for (int i = 1; i <= 50; ++i)
				if (v[i] < pos)
					v[i]++;
			v[t] = 0;
			std::cout << pos + 1 << " ";
		}
}
*/

/*
//1511B
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <functional>
int sz (int x)
{
	int res = 0;
	while (x > 0)
		{
			x /= 10;
			++res;
		}
	return res;
}
int main ()
{
	int t, a, b, c, a0, b0, c0;
	std::cin >> t;
	while (t--)
		{
			std::cin >> a >> b >> c;
			c0 = 1;
			for (int i = 1; i < c; ++i)
				c0 *= 10;
			a0 = c0;
			b0 = c0;
			while (sz (a0) != a)
				a0 *= 2;
			while (sz (b0) != b)
				b0 *= 3;
			std::cout << a0 << " " << b0 << "\n";
		}
}
*/

/*
//1511
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <functional>
int main ()
{
	int t, n, r;
	std::cin >> t;
	while (t--)
		{
			int ans = 0;
			std::cin >> n;
			while (n--)
				{
					std::cin >> r;
					if (r != 2)
						++ans;
				}
			std::cout << ans << "\n";
		}
}
*/

/*
//WRONG
//1512G
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <functional>
int main ()
{
	const int inf = 10000000;
	std::vector<int> v (inf + 7, 1);
	for (int i = 2; i <= inf; ++i)
		{
			if (v[i] == 1)
				{
					for (int j = v[i]; j <= inf; j += v[i])
						v[j] += i;
				}
			else
				v[i] += i;
		}
	std::unordered_map<int, int> m;
	for (int i = inf; i > 0; --i)
		m[v[i]] = i;
	int t, n, c;
	std::cin >> t;
	while (t--)
		{
			std::cin >> c;
			if (m.count (c))
				std::cout << m[c] << "\n";
			else
				std::cout << "-1\n";
		}
}
*/

/*
//WRONG
//1512E
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <functional>
int main ()
{
	int t, n, l, r, s;
	std::vector<int> a;
	std::cin >> t;
	while (t--)
		{
			std::cin >> n >> l >> r >> s;
			std::unordered_set<int> set;
			for (int i = 1;i <= n; ++i)
				set.insert (i);
			a.resize (r - l + 1);
			for (int i = 1; i <= r - l + 1; ++i)
				a[i] = *set.begin (),
				set.erase (set.begin ()),
				s -= i;
			if (s < 0)
				{
					std::cout << -1;
					continue;
				}

		}
}
*/

/*
//1512D
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <functional>
int main ()
{
	int t, n, i_mx, i_x;
	std::vector<long long> a;
	std::cin >> t;
	while (t--)
		{
			std::cin >> n;
			a.resize (n + 2);
			long long sum = 0;
			for (int i = 0; i < n + 2; ++i)
				std::cin >> a[i],
				sum += a[i];
			std::sort (a.begin (), a.end ());
			sum -= a.back ();
			bool ok = false;
			for (int i = 0; i < n + 1 && !ok; ++i)
				if (sum - a[i] == a.back ())
					{
						i_x = i;
						ok = true;
					}
			if (!ok)
				{
					if (sum - a[a.size () - 2] == a[a.size () - 2])
						{
							i_x = a.size () - 2;
							ok = true;
						}
				}
			if (!ok)
				{
					std::cout << "-1\n";
				}
			else
				{
					for (int i = 0; i < n + 1; ++i)
						if (i != i_x)
							std::cout << a[i] << " ";
					std::cout << "\n";
				}
		}
}
*/

/*
//1512C
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <functional>
int main ()
{
	int t, a[2];
	std::string s;
	std::cin >> t;
	while (t--)
		{
			std::cin >> a[0] >> a[1] >> s;
			int n = s.size ();
			for (int i = 0; i < n; ++i)
				{
					if (s[i] == '?') continue;;
					a[s[i] - '0']--;
				}
			bool ok = (a[0] >= 0) && (a[1] >= 0);
			for (int i=0; i < n / 2 && ok; ++i)
				{
					if (s[i] == '?')
						{
							if (s[n - i - 1] == '?')
								continue;
							a[s[n - i - 1] - '0']--;
							s[i] = s[n - i - 1];
							if (a[s[n - i - 1] - '0'] < 0)
								ok = false;
						}
					else
						{
							if (s[i] == s[n - i - 1])
								continue;
							if (s[n - i - 1] == '?')
								{
									a[s[i] - '0']--;
									s[n - i - 1] = s[i];
									if (a[s[i] - '0'] < 0)
										ok = false;
									continue;
								}
							ok = false;
						}
				}
			for (int i=0; i < n / 2 && ok; ++i)
				if (s[i] == '?')
					{
						if (a[0] >= 2)
							{
								s[i] = '0';
								s[n - i - 1] = '0';
								a[0] -= 2;
							}
						else if (a[1] >= 2)
							{
								s[i] = '1';
								s[n - i - 1] = '1';
								a[1] -= 2;
							}
						else
							ok = false;
					}
			if (n % 2 == 1)
				{
					int i = n / 2;
					if (s[i] == '?')
						{
							if (a[0] > 0)
								s[i] = '0',
								a[0]--;
							else if (a[1] > 0)
								s[i] = '1',
								a[1]--;
							else
								ok = false;
						}
				}
			ok = ok && (a[0] == 0) && (a[1] == 0);
			std::cout << (ok ? s : "-1") << "\n";
		}
}
*/

/*
//1512B
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <functional>
int main ()
{
	int t, n;
	std::vector<std::string> a;
	std::cin >> t;
	while (t--)
		{
			std::cin >> n;
			a.resize (n);
			for (int i = 0; i < n; ++i)
				std::cin >> a[i];
			std::vector<std::pair<int, int>> b;
			for (int i = 0; i < n; ++i)
				{
					for (int j = 0; j < n; ++j)
						{
							if (a[i][j] == '*')
								b.push_back ({i, j});
						}
				}
			if (b[0].first == b[1].first)
				{
					if (b[0].first == n - 1)
						{
							a[b[0].first - 1][b[0].second] = '*';
							a[b[1].first - 1][b[1].second] = '*';
						}
					else
						{
							a[b[0].first + 1][b[0].second] = '*';
							a[b[1].first + 1][b[1].second] = '*';
						}
				}
			else
			if (b[0].second == b[1].second)
				{
					if (b[0].second == n - 1)
						{
							a[b[0].first][b[0].second - 1] = '*';
							a[b[1].first][b[1].second - 1] = '*';
						}
					else
						{
							a[b[0].first][b[0].second + 1] = '*';
							a[b[1].first][b[1].second + 1] = '*';
						}
				}
			else
				{
					a[b[0].first][b[1].second] = '*';
					a[b[1].first][b[0].second] = '*';
				}
			for (int i = 0; i < n; ++i)
				std::cout << a[i] << "\n";
		}
}
*/

/*
//1512A
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <functional>
int main ()
{
	int t, n, k;
	std::vector<int> a;
	std::cin >> t;
	while (t--)
		{
			std::cin >> n;
			a.resize (n);
			std::unordered_map<int, int> m, c;
			for (int i=0; i < n; ++i)
				std::cin >> a[i],
				m[a[i]] = i + 1,
				c[a[i]]++;
			if (c.begin ()->second == 1)
				{
					std::cout << m[c.begin ()->first] << "\n";
					continue;
				}
			c.erase (c.begin ());
			std::cout << m[c.begin ()->first] << "\n";
		}
}
*/

/*
#include <iostream>
#include <vector>
#include <algorithm>
int main ()
{
	const int SIZE = 1000000000;
	std::vector<int> v;
	v.reserve (SIZE);
	for (int i = 0; i < SIZE; ++i)
		v.push_back (i);
	std::random_shuffle (v.begin (), v.end ());
	std::cout << v.size () << "\n";
	//for (const int i : v)
	//	std::cout << i << " ";
}
*/

/*
//1498C
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <functional>
int dp[1001][1001][2], n;
const int mod = 1e9 + 7;
int make (const int pos, const int k, const int dir)
{
	if (k == 1) return 1;
	if (dp[pos][k][dir] != -1)
		return dp[pos][k][dir];
	int ans = 2;
	if (dir == 1)
		{
			if (pos < n)
				ans += make (pos + 1, k, dir) - 1;
			ans %= mod;
			if (pos > 1)
				ans += make (pos - 1, k - 1, 1 - dir) - 1;
			ans %= mod;
		}
	else
		{
			if (pos > 1)
				ans += make (pos - 1, k, dir) - 1;
			ans %= mod;
			if (pos < n)
				ans += make (pos + 1, k - 1, 1 - dir) - 1;
			ans %= mod;
		}
	dp[pos][k][dir] = ans;
	return ans;
}

int main ()
{
	int t, k;
	std::cin >> t;
	while (t--)
		{
			std::cin >> n >> k;
			memset (dp, -1, sizeof (dp));
			std::cout << make (1, k, 1) << "\n";
		}
}
*/

/*
//1498B
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <functional>
int main ()
{
	std::unordered_map<int, int> d2;
	std::unordered_map<int, int> d2d;
	int D = 1, Dn = 0;
	while (D <= 1000000)
		d2[D] = Dn,
		d2d[Dn] = D,
		++Dn,
		D *= 2;

	std::vector<int> d (Dn);
	int t, n, W;
	std::vector<int> w;
	std::cin >> t;
	while (t--)
		{
			std::cin >> n >> W;
			w.resize (n);
			for (int i=0; i < n; ++i)
				std::cin >> w[i],
				d[d2[w[i]]]++;

			int ans = 0;
			int dmx = d.size () - 1;
			while (dmx >= 0)
				{
					if (W % d2d[dmx] == 0 && d2d[dmx] * d[dmx] >= W)
						{
							int ct = W / d2d[dmx];
							ans += d[dmx] / ct;
							d[dmx] %= ct;
						}
					while (dmx >= 0 && d[dmx] == 0)
						--dmx;
					if (dmx < 0)
						break;
					int Wt = W;
					for (int i = dmx; i >= 0 && Wt > 0; --i)
						if (Wt >= d2d[i] && d[i] > 0)
							{
								int ct = std::min (d[i], Wt / d2d[i]);
								d[i] -= ct;
								Wt -= ct * d2d[i];
							}
					++ans;
				}
			std::cout << ans << "\n";
		}
}
*/

/*
//1498A
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <functional>
long long gcd(long long a, long long b) {
	while (b) {
		a %= b;
		std::swap(a, b);
	}
	return a;
}
int sm (long long a)
{
	int res = 0;
	while (a > 0)
		res += a % 10,
		a /= 10;
	return res;
}
int main ()
{
	int t;
	long long n;
	std::cin >> t;
	while (t--)
		{
			std::cin >> n;
			while (gcd (n, sm (n)) == 1)
				++n;
			std::cout << n << "\n";
		}
}
*/

/*
//1506G
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
int main ()
{
	int t;
	std::string s;
	std::cin >> t;
	while (t--)
		{
			std::cin >> s;
			//std::vector<std::pair<int, char>> ans;
			ans.reserve (26);
			std::vector<std::vector<int>> alf (26);
			for (int i = 0; i < s.size (); ++i)
				alf[s[i]-'a'].push_back (i);

			std::string ans;
			for (int i=0;i<s.size ();++i)
				if (alf[s[i] - 'a'].size () == 1)
					ans.push_back (s[i])
			for (int i = 0; i < 26; ++i)
				std::sort (alf[i].begin (), alf[i].end ());
			std::vector<int> last;
			for (int i = 25; i >= 0; --i)
				{
					const char q = i + 'a';
					const std::vector<int> &a = alf[i];
					if (a.empty ()) continue;
					auto it = a.end ();
					if (last.empty ())
						{
							--it;
							last.push_back (*it);
						}
					else
						{
							for (const int cur_last : last)
								{
									it = std::lower_bound (a.begin (), a.end (), cur_last);
									if (it != a.end ())
										break;
								}
							if (it == a.end ())
								--it;
							last.push_back (*it);
						}
					ans.push_back (std::make_pair (*it, q));
				}
			std::sort (ans.begin (), ans.end ());
			for (const auto el : ans)
				std::cout << el.second;
			std::cout << "\n";
		}
}
*/

/*
//1506E
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <functional>
int main ()
{
	int t, n;
	std::vector<int> q, a, b;
	std::cin >> t;
	while (t--)
		{
			std::cin >> n;
			q.resize (n); a.resize (n); b.resize (n);
			std::set<int> aset;
			std::set<int, std::greater<int>> bset;
			// for (int i=1;i<=n;++i)
			// 	aset.insert (i),
			// 	bset.insert (i);
			for (int i = 0; i < n; ++i)
				std::cin >> q[i];
			a[0] = q[0];
			b[0] = q[0];
			for (int i = 1; i < q[0]; ++i)
				aset.insert (i),
				bset.insert (i);
			for (int i = 1; i < n; ++i)
				{
					if (q[i] == q[i - 1])
						{
							a[i] = *aset.begin ();
							aset.erase (aset.begin ());
							b[i] = *bset.begin ();
							bset.erase (bset.begin ());
						}
					else
						{
							a[i] = q[i];
							b[i] = q[i];
							for (int j = q[i - 1] + 1; j < q[i]; ++j)
								aset.insert (j),
								bset.insert (j);
						}
				}
			for (int i = 0; i < n; ++i)
				std::cout << a[i] << " ";
			std::cout << "\n";
			for (int i = 0; i < n; ++i)
				std::cout << b[i] << " ";
			std::cout << "\n";
		}
}
*/

/*
//1506D
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
int main ()
{
	int t, n;
	std::vector<int> a;
	std::cin >> t;
	while (t--)
		{
			std::unordered_map<int, int> m;
			std::cin >> n;
			a.resize (n);
			for (int i=0; i < n; ++i)
				{
					std::cin >> a[i];
					m[a[i]]++;
				}
			int mx = 0;
			for (const auto el : m)
				mx = std::max (mx , el.second);
			if (mx <= n / 2)
				std::cout << n % 2 << "\n";
			else
				std::cout << mx * 2 - n << "\n";
		}
}
*/

/*
//1506C
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
std::unordered_set<std::string> make (const std::string &s)
{
	std::unordered_set<std::string> res;
	int n = s.size ();
	for (int i = 0; i < s.size (); ++i)
		for (int j = 0; j <= s.size () - i; ++j)
			res.insert (s.substr (i, j));
	return res;
}
int main ()
{
	int t;
	std::string a, b;
	std::cin >> t;
	while (t--)
		{
			std::cin >> a >> b;
			std::unordered_set<std::string> aset = make (a);
			std::unordered_set<std::string> bset = make (b);
			int ans = a.size () + b.size ();
			for (const std::string &ai : aset)
				{
					if (bset.count (ai))
						ans = std::min (ans, (int)(a.size () + b.size () - ai.size () * 2));
				}
			std::cout << ans << "\n";
		}
}
*/

/*
//1506B
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
int main ()
{
	int t, n, k;
	std::string s;
	std::cin >> t;
	while (t--)
		{
			int ans = 0;
			std::cin >> n >> k >> s;
			int st = 0, en = n - 1;
			while (s[st] == '.')
				++st;
			s[st] = 'x';
			++ans;
			while (s[en] == '.')
				--en;
			if (s[en] == 'x')
				{
					std::cout << "1\n";
					continue;
				}
			s[en] = 'x';
			++ans;
			int it = st + k;
			while (it < en)
				{
					while (s[it] == '.')
						--it;
					s[it] = 'x';
					++ans;
					it += k;
				}
			std::cout << ans << "\n";
		}
}
*/

/*
//1506A
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
int main ()
{
	long long t, n, m, x;
	std::cin >> t;
	while (t--)
		{
			std::cin >> n >> m >> x;
			int a = (x - 1) % n + 1;
			int b = x / n + (x % n ? 1 : 0);
			std::cout << (a - 1) * m + b << "\n";
		}
}
*/


/*
//1493D	--2100
#include <iostream>
#include <vector>
#include <unordered_map>
const int inf = 200046;
const int ans_inf = 1000000007;
std::vector<std::unordered_map<int, int>> d (inf);
std::vector<int> v [inf];
long long ans = 1;
void add_to_v (const std::unordered_map<int, int> &mp)
{
	for (const auto el : mp)
		{
			auto &vec = v[el.first];
			if (vec.size () < el.second)
				vec.resize (el.second, 0);
			for (int i = 0; i < el.second; ++i)
				vec[i]++;
		}
}
int main ()
{
	for (int i = 1; i < inf; ++i)
		{
			for (int j = 2; j * j <= i; ++j)
				if (i % j == 0)
					{
						for (const auto el : d[i / j])
							d[i][el.first] = el.second;
						d[i][j]++;
						break;
					}
			if (d[i].empty ())
				d[i][i]++;
		}

	int n, q, x;
	std::cin >> n >> q;
	std::vector<std::unordered_map<int, int>> a (n);
	for (int i = 0; i < n; ++i)
		{
			std::cin >> x;
			a[i] = d[x];
			add_to_v (a[i]);
		}

	for (int i = 1; i < inf; ++i)
		{
			for (const int j : v[i])
				if (j == n)
					ans = (ans * i) % ans_inf;
				else
					break;
		}

	while (q--)
		{
			int i;
			std::cin >> i >> x;
			--i;
			for (const auto el : d[x])
				{
					auto &vec = v[el.first];
					if (vec.size () < a[i][el.first] + el.second)
						vec.resize (a[i][el.first] + el.second, 0);
					for (int j = a[i][el.first]; j < a[i][el.first] + el.second; ++j)
						{
							vec[j]++;
							if (vec[j] == n)
								ans = (ans * el.first) % ans_inf;
						}
					a[i][el.first] += el.second;
				}
			std::cout << ans << "\n";
		}
}
*/

/*
//1491G	--2800
// WRONG
#include <iostream>
#include <vector>
#include <unordered_map>
int main ()
{
	int n;
	std::cin >> n;
	std::vector<int> c (n);
	std::unordered_map<int, int> m;
	for (int i = 0; i < n; ++i)
		{
			std::cin >> c[i];
			if (c[i] != i)
				m[i] = c[i];
		}
	std::vector<std::pair<int, int>> v;
	v.reserve (m.size ());
	std::vector<std::pair<int, int>> ans;
	ans.reserve (n);
	while (m.size () > 3)
		{
			auto a = m.begin ();
			auto b = m.begin ();
			while (a->first == b->first || a->first == b->second || a->second == b->first)
				++b;
			v.push_back (std::make_pair (a->first, b->second));
			v.push_back (std::make_pair (b->first, a->second));
			ans.push_back (std::make_pair (a->first, b->first));
			m.erase (a->first);
			m.erase (b->first);
		}
}
*/

/*
//1499D	--2100
// THNX dlalswp25
#include <iostream>
#include <vector>
const int inf = 20000000;
int sieve[20000046];
std::vector<int> primes;
int c, d, x;
long long ans;
void make (const int z)
{
	int y = x / z + d;
	if (y % c) return;
	y /= c;
	int cnt = 0, last = 0;
	while (y > 1)
		{
			const int l = sieve[y];
			if (last != l)
				++cnt,
				last = l;
			y /= l;
		}
	ans += (1 << cnt);
}
int main ()
{
	for(int i = 2; i <= inf; i++)
		{
			if(!sieve[i])
				sieve[i] = i,
				primes.push_back(i);
			for(int j : primes)
				{
					if(i * j > inf) break;
					sieve[i * j] = j;
					if(i % j == 0) break;
				}
		}
	int t;
	std::cin >> t;
	while (t--)
		{
			std::cin >> c >> d >> x;
			ans = 0;
			for (int i = 1; i * i <= x; ++i)
				{
					if (x % i) continue;
					make (i);
					if (x / i != i) make (x / i);
				}
			std::cout << ans << "\n";
		}
}
*/

/*
//WRONG
//1499D
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
struct hash_pair final {
	template<class TFirst, class TSecond>
	size_t operator()(const std::pair<TFirst, TSecond>& p) const noexcept
	{
		uintmax_t hash = std::hash<TFirst>{}(p.first);
		hash <<= sizeof(uintmax_t) * 4;
		hash ^= std::hash<TSecond> {} (p.second);
		return std::hash<uintmax_t> {} (hash);
	}
};
template <typename T>
T nod (T a, T b)
{
	while (a && b)
		if (a >= b) a %= b;
		else b %= a;
	return a | b;
}
int t, c, d, x;
//std::unordered_set<std::pair<int, int>, hash_pair> ans;
int ans;
void check (const int X)
{
	int y = X + d;
	if (y % c != 0)
		return;
	y /= c;
	for (int i = 1; i*i < y; ++i)
		if (y % i == 0 && nod (i, y / i) == 1)
			if (x / X * i != x / X * y / i)
				ans += 2;
			else
				++ans;
			//ans.insert ({x / X * i, x / X * y / i}),
			//ans.insert ({x / X * y / i, x / X * i});
	long long f = 1LL * c * x / X * x / X;
	if (c != d && c - d == X)
		//ans.insert ({x / X, x / X});
		++ans;
	return;
}
int main ()
{
	std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);
	std::cin >> t;
	while (t--)
		{
			std::cin >> c >> d >> x;
			//ans.clear ();
			ans = 0;
			for (int i = 1;i*i <= x;++i)
				if (x % i == 0)
					{
						check (i);
						if (i != x / i)
							check (x / i);
					}
			std::cout << ans << "\n";
			//std::cout << ans.size () << "\n";
		}
}
*/

/*
//1484A
#include <iostream>
int main ()
{
	int t, a, b;
	std::cin >> t;
	while (t--)
		{
			std::cin >> a >> b;
			std::cout << a * b << "\n";
		}
}
*/

/*
//1480B	--900
#include <iostream>
#include <vector>
#include <algorithm>
int main ()
{
	int t, A, B, n;
	std::vector<int> a, b;
	std::cin >> t;
	while (t--)
		{
			std::cin >> A >> B >> n;
			a.resize (n); b.resize (n);
			for (int i=0;i<n;++i) std::cin >> a[i];
			for (int i=0;i<n;++i) std::cin >> b[i];
			long long s = 0 ,mxn = 0;
			for (int i=0;i<n;++i)
				{
					s += 1LL * (b[i] + A - 1) / A * a[i];
					mxn = std::max (mxn, 1LL * a[i]);
				}
			s -= mxn;
			std::cout << (s < B ? "YES\n" : "NO\n");
		}
}
*/

/*
//1486A	--900
#include <iostream>
#include <vector>
int main ()
{
	int t, n;
	std::vector<int> h;
	std::cin >> t;
	while (t--)
		{
			long long shifts = 0;
			bool ok = true;
			std::cin >> n;
			h.resize (n);
			for (int i=0;i<n;++i)
				{
					std::cin >> h[i];
					shifts += h[i] - i;
					if (shifts < 0)
						ok = false;
				}
			std::cout << (ok ? "YES\n" : "NO\n");
		}
}
*/

/*
//1499C
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
int main ()
{
	std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);
	long long t, n, k;
	std::vector<long long> c;
	std::vector<long long> a;
	std::cin >> t;
	while (t--)
		{
			std::cin >> n;
			c.resize (n);
			a.resize (n);
			for (int i=0;i<n;++i)
				std::cin >> c[i];
			a[0] = c[0];
			for (int i=1;i<n;++i)
				a[i] = a[i - 1] + c[i];

			long long ans = 1000000000000000007LL;
			std::multiset<long long> s[2];
			s[0].insert (c[0]);
			for (int i = 1; i < n; ++i)
				{
					s[i%2].insert (c[i]);
					long long x = *s[0].begin ();
					long long y = *s[1].begin ();
					ans = std::min (ans, a[i]
															 + x * (n - (long long)s[0].size ())
															 + y * (n - (long long)s[1].size ()));
				}
			std::cout << ans << "\n";
		}
}
*/

/*
//1499B
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
int main ()
{
	std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);
	int t, n, k;
	std::string s;
	std::cin >> t;
	while (t--)
		{
			std::cin >> s;
			n = s.size ();
			int i = 0;
			while (i < n && s[i] == '0')
				++i;
			if (i != n)
				{
					int j = n - 1;
					int cnt = 0;
					while (j > i && cnt < 2)
						{
							if (s[j] == '0')
								++cnt;
							else
								cnt = 0;
							--j;
						}
					if (i != j)
						{
							cnt = 0;
							while (j >= i && cnt < 2)
								{
									if (s[j] == '1')
										++cnt;
									else
										cnt = 0;
									--j;
								}
							if (cnt == 2)
								{
									std::cout << "NO\n";
									continue;
								}
						}
				}
			std::cout << "YES\n";
		}
}
*/

/*
//1499A
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
int main ()
{
	std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);
	int t, n, k1, k2, w, b;
	std::cin >> t;
	while (t--)
		{
			std::cin >> n >> k1 >> k2 >> w >> b;
			w -= std::min (k1, k2);
			w -= std::abs (k1 - k2) / 2;
			k1 = n - k1;
			k2 = n - k2;
			b -= std::min (k1, k2);
			b -= std::abs (k1 - k2) / 2;
			if (w <= 0 && b <= 0)
				std::cout << "YES\n";
			else
				std::cout << "NO\n";
		}
}
*/


/*
//1497E1	--1700
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
int main ()
{
	std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);
	int t, n, k;
	std::vector<int> a, b;
	std::cin >> t;
	while (t--)
		{
			std::cin >> n >> k;
			a.resize (n);
			b.resize (n);
			for (int i=0;i<n;++i)
				{
					std::cin >> a[i];
					for (int j=2; j*j <= a[i]; ++j)
						{
							while (a[i] % (j*j) == 0)
								{
									a[i] /= j*j;
								}
						}
				}
			int ans = 1;
			std::unordered_set<int> m;
			for (int i=0;i<n;++i)
				{
					if (m.count (a[i]))
						{
							++ans;
							m.clear ();
						}
					m.insert (a[i]);
				}
			std::cout << ans << "\n";
		}
}
*/

/*
//1497C2	--1600; 1492C1	--1200
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>

void make (const int n, const int k, std::vector<int> &res)
{
	if (n % k == 0)
		{
			res = std::vector<int> (k, n / k);
			return;
		}
	if (k * 2 > n)
		{
			res = std::vector<int> (k, 1);
			for (int i = 0; i < n % k; ++i)
				res[i]++;
			return;
		}
	if (n % 2 == 1)
		{
			make (n - 1, k - 1, res);
			res.push_back (1);
			return;
		}
	make (n / 2, k, res);
	for (int &el : res)
		el *= 2;
}
int main ()
{
	std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);
	int t, n, k;
	std::cin >> t;
	while (t--)
		{
			std::cin >> n >> k;
			std::vector<int> ans;
			make (n, k, ans);
			for (const int el : ans)
				std::cout << el << " ";
			std::cout << "\n";
		}
}
*/

/*
//1497B	--1200
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
int main ()
{
	std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);
	int t, n, m;
	std::vector<int> a;
	std::cin >> t;
	while (t--)
		{
		std::unordered_map<int, int> map;
			std::cin >> n >> m;
			a.resize (n);
			for (int i=0;i<n;++i)
				std::cin >> a[i],
				map[a[i] % m]++;
			int ans = 0;
			if (map.count (0))
				{
					map.erase (0);
					++ans;
				}
			if (m % 2 == 0 && map.count (m / 2))
				{
					map.erase (m / 2);
					++ans;
				}
			while (map.size () > 0)
				{
					auto x = *map.begin ();
					if (!map.count (m - x.first))
						{
							ans += x.second;
						}
					else
						{
							ans += std::max (1, std::abs (x.second - map[m - x.first]));
							map.erase (m - x.first);
						}
					map.erase (x.first);
				}
			std::cout << ans << "\n";
		}
}
*/

/*
//1497A	--800
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
int main ()
{
	std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);
	int t, n, k, p;
	std::vector<int> a (107);
	std::cin >> t;
	while (t--)
		{
			std::cin >> n;
			for (int i=0;i<n;++i)
				std::cin >> p,
				a[p]++;
			for (int i=0;i<=100;++i)
				if (a[i])
					{
						std::cout << i << " ";
						a[i]--;
					}
			for (int i=0;i<=100;++i)
				while (a[i])
					{
						std::cout << i << " ";
						a[i]--;
					}
			std::cout << "\n";
		}
}
*/



/*
//1494C	--1900
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
int make (const std::vector<int> &a, const std::vector<int> &b)
{
	int ans = 0;
	const auto start_a = std::upper_bound (a.begin (), a.end (), 0);
	const auto start_b = std::upper_bound (b.begin (), b.end (), 0);

	if (start_a == a.end ())
		return ans;

	std::unordered_set<int> s;
	for (auto it = start_a; it != a.end (); ++it)
		s.insert (*it);
	std::vector<int> v (b.size () + 1);
	for (auto it = start_b; it != b.end (); ++it)
		if (s.count (*it))
			v[it - b.begin ()]++;
	for (int i = v.size () - 2; i >= 0; --i)
		v[i] += v[i + 1];

	auto last_b = b.end ();
	for (int i = b.size () - 1; i>=0 && b[i] > 0; --i)
		{
			last_b--;
			auto last_a = std::lower_bound (start_a, a.end (), b[i]);
			if (last_a == a.end ())
				--last_a;
			if (*last_a > b[i])
				{
					if (last_a == a.begin ())
						continue;
					--last_a;
					if (*last_a > b[i] || *last_a < 0)
						continue;
				}
			int cnt = last_a - start_a;
			auto first_b = std::lower_bound (start_b, last_b, b[i] - cnt);
			ans = std::max (ans, static_cast<int> (last_b - first_b + 1) + v[last_b - b.begin () + 1]);
		}
	return ans;
}
int main ()
{
	int t, n, m;
	std::vector<int> a, b;
	std::cin >> t;
	while (t--)
		{
			std::cin >> n >> m;
			a.resize (n);
			b.resize (m);
			for (int i=0;i<n;++i)
				std::cin >> a[i];
			for (int i=0;i<m;++i)
				std::cin >> b[i];
			int ans = make (a, b);
			for (int &el : a) el = -el;
			for (int &el : b) el = -el;
			std::reverse (a.begin (), a.end ());
			std::reverse (b.begin (), b.end ());
			ans += make (a, b);
			std::cout << ans << "\n";
		}
}
*/

/*
//1481A	--800
#include <iostream>
#include <string>
#include <vector>
void no ()
{
	std::cout << "NO\n";
}
int main ()
{
	int t, px, py, x, y;
	std::string s;
	std::cin >> t;
	while (t--)
		{
			std::vector<int> v (4, 0);
			std::cin >> px >> py >> s;
			for (const char q : s)
				if      (q == 'R') v[0]++;
				else if (q == 'L') v[1]++;
				else if (q == 'U') v[2]++;
				else               v[3]++;
			x = v[0] - v[1];
			y = v[2] - v[3];
			if (px > x)
				{
					if (px - x > v[1])
						{
							std::cout << "NO\n";
							continue;
						}
				}
			else if (px < x)
				{
					if (x - px > v[0])
						{
							std::cout << "NO\n";
							continue;
						}
				}
			if (py > y)
				{
					if (py - y > v[3])
						{
							std::cout << "NO\n";
							continue;
						}
				}
			else if (py < y)
				{
					if (y - py > v[2])
						{
							std::cout << "NO\n";
							continue;
						}
				}
			std::cout << "YES\n";
		}
}
*/

/*
//1501D	--2200
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
template <class T>
T nod (T a, T b)
{
	while (a && b)
		if (a >= b) a %= b;
		else b %= a;
	return a | b;
}
template <class T>
T nok (T a, T b)
{
	return (a * b) / nod (a, b);
}
void read (const int n, std::vector<int> &a, const int m, std::vector<int> &b)
{
	a.resize (n);
	b.resize (m);
	for (int i = 0;i<n;++i)
		std::cin >> a[i];
	for (int i = 0;i<m;++i)
		std::cin >> b[i];
}
int main ()
{
	std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);
	int n, m;
	long long k;
	std::cin >> n >> m >> k;
	std::vector<int> a, b;
	if (n >= m)
		read (n, a, m, b);
	else
		{
			std::swap (n, m);
			read (m, b, n, a);
		}
	std::unordered_map<int, int> n_order;
	for (int i=0;i<n;++i)
		n_order[a[i]] = i;

	std::vector<int> m_del (n);
	std::unordered_map<int, int> m_order;
	for (int i=0;i<m;++i)
		m_order[b[i]] = i;
	for (int i=0;i<n;++i)
		{
			if (!m_order.count (a[i])) continue;
			int p = i - m_order[a[i]];
			if (p < 0) p = (p + n) % n;
			m_del[p]++;
		}

	long long days = nok (static_cast<long long> (n), static_cast<long long> (m));
	std::unordered_map<long long, long long> kd;
	int io = 0, old_io = 0;
	kd[io] = m - m_del[io];
	io = (io + m) % n;
	while (io)
		{
			kd[io] = m - m_del[io] + kd[old_io];
			old_io = io;
			if (kd[io] >= k) break;
			io = (io + m) % n;
		}
	int last_io = old_io;

	long long ans = 0;
	if (k > kd[last_io])
		{
			long long crcl_num = k / kd[last_io];
			k %= kd[last_io];
			ans = crcl_num * days;
		}
	if (!k)
		{
			while (a[(ans - 1) % n] == b[(ans - 1) % m])
				--ans;
		}
	if (k)
		{
			io = 0;
			old_io = io;
			while (k >= kd[io])
				{
					old_io = io;
					io = (io + m) % n;
					ans += m;
					if (k <= kd[old_io]) break;
				}
			if (k >= kd[old_io])
				k -= kd[old_io];
		}
	while (k > 0)
		{
			if (a[ans % n] != b[ans % m])
				--k;
			++ans;
		}
	std::cout << ans;
}
*/

/*
//1501C	--1800
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
void no ()
{
	std::cout << "NO\n";
	exit (0);
}
void yes (int x, int y, int z, int w)
{
	std::cout << "YES\n" << x  << " " << y << " " << z << " " << w << "\n";
	exit (0);
}
std::vector<std::pair<int, int>> sum (5e6+46);
int main ()
{
	std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);
	int n;
	std::cin >> n;
	std::vector<int> a (n + 1);
	for (int i=1;i<=n;++i)
		std::cin >> a[i];
	for (int i = 1; i <= n; ++i)
		{
			for (int j = i + 1; j <= n; ++j)
				{
					int s = a[i] + a[j];
					if (!sum[s].first)
						{
							sum[s] = std::make_pair (i, j);
							continue;
						}
					if (i != sum[s].first && i != sum[s].second && j != sum[s].first && j != sum[s].second)
						yes (i, j, sum[s].first, sum[s].second);
				}
		}
	no ();
}
*/

/*
//1501B	--900
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
void no ()
{
	std::cout << "0\n";
	exit (0);
}
int main ()
{
	std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);
	int t, n, x;
	std::vector<std::pair<int, int>> a;
	std::vector<int> ans;
	std::cin >> t;
	while (t--)
		{
			std::cin >> n;
			a.clear ();
			a.reserve (n);
			ans.clear ();
			ans.resize (n + 1, 0);
			for (int i=1;i<=n;++i)
				{
					std::cin >> x;
					if (!x) continue;
					if (x <= 10)
						{
							for (int j = std::max (1, i - x + 1); j <= i; ++j)
								ans[j] = 1;
							continue;
						}
					a.push_back ({std::max (1, i - x + 1), i});
				}

			std::sort (a.begin (), a.end ());
			int k = 1;
			for (const auto el : a)
				{
					if (el.first > k)
						k = el.first;
					while (k <= el.second)
						ans[k++] = 1;
				}

			for (int i=1;i<=n;++i)
				std::cout << ans[i] << " ";
			std::cout << "\n";
		}
}
*/

/*
//1501A	--800
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
void no ()
{
	std::cout << "0\n";
	exit (0);
}
int main ()
{
	std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);
	int t, n, a[200], b[200], tm[200];
	std::cin >> t;
	b[0] = 0;
	a[0] = 0;
	tm[0] = 0;
	while (t--)
		{
			std::cin >> n;
			for (int i=1;i<=n;++i)
				std::cin >> a[i] >> b[i];
			for (int i=1;i<=n;++i)
				std::cin >> tm[i];
			int time = 0;
			for (int i=1;i<=n;++i)
				{
					time += a[i] - b[i - 1] + tm[i];
					if (i != n)
						{
							time += (b[i] - a[i]) / 2 + (b[i] - a[i]) % 2;
							if (time < b[i])
								time = b[i];
						}
				}
			std::cout << time << "\n";
		}
}
*/


/*
//1491F	--2700
#include <iostream>
#include <vector>
int get_result ()
{
	std::cout.flush ();
	int F;
	std::cin >> F;
	return F;
}
int ask_to (const int i)
{
	std::cout << "? 1 " << i - 1 << "\n" << i << "\n";
	for (int j = 1; j < i; ++j)
		std::cout << j << " ";
	std::cout << "\n";
	return get_result ();
}
int ask (const int i, const int j)
{
	std::cout << "? 1 1\n" << i << "\n" << j << "\n";
	return get_result ();
}
int ask (const int i, const std::vector<int> &v)
{
	std::cout << "? 1 " << v.size () << "\n" << i << "\n";
	for (const int j : v)
		std::cout << j << " ";
	std::cout << "\n";
	return get_result ();
}
int main ()
{
	int t, n;
	std::cin >> t;
	std::vector<int> ans, tmp, test;
	while (t--)
		{
			ans.clear ();
			tmp.clear ();
			std::cin >> n;
			int one = 2;
			tmp.push_back (1);
			while (!ask_to (one))
				tmp.push_back (one++);

			for (int i = one + 1; i <= n; ++i)
				if (!ask (one, i))
					ans.push_back (i);

			while (tmp.size () > 1)
				{
					test.clear ();
					int m = tmp.size () >> 1;
					for (int i = 0; i < m; ++i)
						test.push_back (tmp.back ()),
						tmp.pop_back ();
					if (ask (one, test))
						tmp = test;
				}
			for (int i = 1; i < one; ++i)
				if (i != tmp[0])
					ans.push_back (i);

			std::cout << "! " << ans.size () << " ";
			for (const int el : ans)
				std::cout << el << " ";
			std::cout << "\n";
			std::cout.flush ();
		}
}
*/

/*
//1491E	--2400
//THANX Prepared by: Widowmaker and syksykCCC
#include <iostream>
#include <vector>
#define IOS std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
//struct hash_pair final {
//    template<class TFirst, class TSecond>
//    size_t operator()(const std::pair<TFirst, TSecond>& p) const noexcept {
//        uintmax_t hash = std::hash<TFirst>{}(p.first);
//        hash <<= sizeof(uintmax_t) * 4;
//        hash ^= std::hash<TSecond>{}(p.second);
//        return std::hash<uintmax_t>{}(hash);
//    }
//};
std::vector<std::vector<std::pair<int, bool>>> u;
std::vector<int> v;
std::vector<int> fib;

void no ()
{
	std::cout << "NO\n";
	exit (0);
}
void cut_edge (const int edge, const int head, const int k, int &edge1, int &edge2, int &kk)
{
	for (const auto el : u[edge])
		{
			if (edge1 != -1 || el.first == head || el.second == true) continue;
			if (v[el.first] == fib[k - 1] || v[el.first] == fib[k - 2])
				{
					edge1 = edge;
					edge2 = el.first;
					kk = (v[el.first] == fib[k - 1] ? k - 1 : k - 2);
					break;
				}
			cut_edge (el.first, edge, k, edge1, edge2, kk);
		}
}
void count_v (const int edge, const int head)
{
	v[edge] = 1;
	for (const auto el : u[edge])
		{
			if (el.first == head || el.second == true) continue;
			count_v (el.first, edge);
			v[edge] += v[el.first];
		}
}
void check (const int edge, const int k)
{
	if (k <= 1) return;
	count_v (edge, -1);
	int edge1 = -1, edge2 = -1, kk = 0;
	cut_edge (edge, -1, k, edge1, edge2, kk);

	if (edge1 == -1)
		no ();
	for (auto &el : u[edge1]) if (el.first == edge2) el.second = true;
	for (auto &el : u[edge2]) if (el.first == edge1) el.second = true;

	check (edge2, kk);
	check (edge1, (kk == k - 1 ? k - 2 : k - 1));
}
int main ()
{
	IOS;
	int n, a, b;
	std::cin >> n;
	u.resize (n);
	v.resize (n, 0);
	for (int i=1;i<n;++i)
		{
			std::cin >> a >> b;
			a--; b--;
			u[a].push_back ({b, false});
			u[b].push_back ({a, false});
		}

	fib.push_back (1);
	fib.push_back (1);
	while (fib.back () < n)
		fib.push_back (fib[fib.size () - 1] + fib[fib.size () - 2]);
	if (fib.back () != n)
		no ();

	check (0, fib.size () - 1);
	std::cout << "YES\n";
}
*/

/*
//1495B --1900
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
void no ()
{
	std::cout << "0\n";
	exit (0);
}
int main ()
{
	std::ios::sync_with_stdio (false);
	int n;
	std::cin >> n;
	std::vector<int> p (n + 1), a (n + 1), b (n + 1);
	for (int i=1;i<=n;++i)
		{
			std::cin >> p[i];
			if (p[i] > p[i - 1])
				a[i] = a[i - 1] + 1;
			else
				a[i] = 1;
		}
	b[n] = 1;
	for (int i=n-1;i>0;--i)
		if (p[i] > p[i + 1])
			b[i] = b[i + 1] + 1;
		else
			b[i] = 1;

	auto it_mx_a = std::max_element (a.begin (), a.end ());
	auto it_mx_b = std::max_element (b.begin (), b.end ());

	if (*it_mx_a == 1 || *it_mx_b == 1)
		no ();
	int mx = std::max (*it_mx_a, *it_mx_b);
	int ans = 0;
	int ai = -1, bi = -1;
	for (int i = 1;i <= n; ++i)
		{
			if (a[i] == mx)
				{
					if (ai > 0)
						no ();
					ai = i;
				}
			if (b[i] == mx)
				{
					if (bi > 0)
						no ();
					bi = i;
				}
		}
	if (ai == bi && mx % 2 == 1)
		ans = 1;
	std::cout << ans << "\n";
}
*/

/*
//1495A	--1200
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
int main ()
{
	std::ios::sync_with_stdio (false);
	int t, n, x, y;
	std::vector<int> a, b;
	std::cin >> t;
	std::cout.precision(20);
	while (t--)
		{
			std::cin >> n;
			a.clear ();
			b.clear ();
			for (int i=0;i<n * 2;++i)
				{
					std::cin >> x >> y;
					if (x == 0)
						b.push_back (std::abs (y));
					else
						a.push_back (std::abs (x));
				}
			std::sort (a.begin (), a.end ());
			std::sort (b.begin (), b.end ());
			long double ans = 0;
			for (int i=0;i<n;++i)
				ans += std::sqrt (1LL*a[i]*a[i] + 1LL*b[i]*b[i]);
			std::cout << ans << "\n";
		}
}
*/

/*
//1496B	--1100
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
int f (const int a)
{
	return a / 2 + a % 2;
}
int main ()
{
	std::ios::sync_with_stdio (false);
	int t, n, k, max, ai;
	std::set<int> a;
	std::cin >> t;
	while (t--)
		{
			std::cin >> n >> k;
			max = 0;
			a.clear ();
			for (int i=0;i<n;++i)
				std::cin >> ai,
				a.insert (ai);
			int min = 0, max = *a.rbegin (), add = 0;
			while (a.count (min))
				++min;
			while (!a.count (f (min + max)) && k--)
				{
					a.insert (f (min + max));
					while (a.count (min))
						++min;
					max = *a.rbegin ();
					if (min >= max)
						{
							add = k;
							k = 0;
						}
				}
			std::cout << a.size () + add << "\n";
		}
}
*/

/*
//1496A	--900
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
int main ()
{
	std::ios::sync_with_stdio (false);
	int t, n, k;
	std::string s;
	std::cin >> t;
	while (t--)
		{
			std::cin >> n >> k >> s;
			if (n % 2 == 0 && k == n / 2)
				{
					std::cout << "NO\n";
					continue;
				}
			int i = 0, res = 0;
			while (i < n / 2)
				{
					if (s[i] == s[n-1-i])
						++res;
					else
						break;
					++i;
				}
			if (res >= k)
				std::cout << "YES\n";
			else
				std::cout << "NO\n";
		}
}
*/

/*
//1492D	--1900
#include <iostream>
#include <algorithm>
#include <string>
int main ()
{
	int a, b, k;
	std::cin >> a >> b >> k;
	if (b == 1 || a == 0)
		{
			if (k)
				{
					std::cout << "NO\n";
					return 0;
				}
			else
				{
					std::cout << "YES\n";
					std::cout << std::string (b, '1') << std::string (a, '0') << "\n";
					std::cout << std::string (b, '1') << std::string (a, '0') << "\n";
					return 0;
				}
		}
	if (a + b - 1 < k + 1)
		{
			std::cout << "NO\n";
			return 0;
		}

	std::string x, y, z;
	x = std::string (b, '1') + std::string (a, '0');
	y = x;

	if (a == 1)
		{
			y.back () = '1';
			y[a + b - 1 - k] = '0';
		}
	else
		{
			if (k > a)
				{
					std::swap (y[b - 1], y[b - 1 + a]);
					std::swap (y[b - 1], y[b - 1 - k + a]);
				}
			else
				{
					std::swap (y[b - 1], y[b - 1 + k]);
				}
		}

	std::cout << "YES\n" << x << "\n" << y << "\n";
}
*/

/*
//1494B	--1400
#include <iostream>
int main ()
{
	int t, n, a[4], b[4];
	std::cin >> t;
	while (t--)
		{
			std::cin >> n;
			for (int i=0;i<4;++i) std::cin >> a[i];
			bool ok = false;
			for (int i=0, k;i<16 && !ok;++i)
				{
					k = i;
					for (int j=0;j<4;++j)
						b[j] = a[j];
					for (int j=0;j<4;++j)
						{
							b[j] -= k % 2;
							b[(j+1)%4] -= k % 2;
							k /= 2;
						}
					ok = true;
					for (int j=0;j<4;++j)
						if (b[j] < 0 || b[j] > n - 2)
							ok = false;
				}
			std::cout << (ok ? "YES\n" : "NO\n");
		}
}
*/

/*
//1493C --2000
#include <iostream>
#include <set>
#include <vector>
#include <string>
#include <algorithm>
int main ()
{
	int t, n, k;
	std::string s, v;
	std::cin >> t;
	while (t--)
		{
			std::cin >> n >> k >> s;
			if (n % k != 0)
				{
					std::cout << "-1\n";
					continue;
				}
			std::string ans;
			std::vector<int> alf (26, 0);
			int cnt_k = 0;
			auto fill_ans = [&] (int was_size, const std::string &start)
				{
					ans = start;
					if (was_size * k < n)
						ans += std::string (k * (n / k - was_size), 'a');
					for (char q = 'a'; q <= 'z'; ++q)
						if (alf[q - 'a'] && alf[q - 'a'] % k != 0)
							ans += std::string (k - alf[q - 'a'] % k, q);
				};
			for (int i = 0; i < n; ++i)
				{
					for (char q = s[i] + (i < n - 1 ? 1 : 0); q <= 'z'; ++q)
						{
							if (alf[q - 'a'] % k != 0 || (cnt_k + 1) * k <= n)
								{
									int was_size = cnt_k;
									if (alf[q - 'a'] % k == 0)
										++was_size;
									if (was_size * k > n)
										continue;
									alf[q - 'a']++;
									fill_ans (was_size, s.substr (0, i) + q);
									alf[q - 'a']--;
									break;
								}
						}
					if (alf[s[i] - 'a'] % k == 0)
						++cnt_k;
					alf[s[i] - 'a']++;
					if (cnt_k * k > n)
						break;
				}
			if (!ans.empty ())
				std::cout << ans << "\n";
			else
				std::cout << "-1\n";
		}
}
*/

/*
//1493B	--1300
#include <iostream>
#include <set>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <unordered_set>
std::unordered_set<int> good;
int t, h, m, H, M;
char q;
bool check ()
{
	int a = H, A = 0;
	int b = M, B = 0;
	if (a < 10)
		{
			if (!good.count (a))
				return false;
			if (a == 2) a = 5; else if (a == 5) a = 2;
			A = a * 10;
		}
	else
		{
			int a1 = a % 10, a2 = a / 10;
			if (a1 == 2) a1 = 5; else if (a1 == 5) a1 = 2;
			if (a2 == 2) a2 = 5; else if (a2 == 5) a2 = 2;
			if (!good.count (a % 10) || !good.count (a / 10))
				return false;
			A = a1 * 10 + a2;
		}
	if (b < 10)
		{
			if (!good.count (b))
				return false;
			if (b == 2) b = 5; else if (b == 5) b = 2;
			B = b * 10;
		}
	else
		{
			int a1 = b % 10, a2 = b / 10;
			if (a1 == 2) a1 = 5; else if (a1 == 5) a1 = 2;
			if (a2 == 2) a2 = 5; else if (a2 == 5) a2 = 2;
			if (!good.count (b % 10) || !good.count (b / 10))
				return false;
			B = a1 * 10 + a2;
		}
	return A < m && B < h;
}
void inc ()
{
	if (M == m - 1)
		{
			M = 0;
			if (H == h - 1)
				H = 0;
			else
				++H;
		}
	else
		++M;
}
int main ()
{
	good.insert (0);
	good.insert (1);
	good.insert (2);
	good.insert (5);
	good.insert (8);
	std::cin >> t;
	while (t--)
		{
			std::cin >> h >> m >> H >> q >> M;
			while (!check ())
				inc ();
			if (H < 10)
				std::cout << "0";
			std::cout << H << ":";
			if (M < 10)
				std::cout << "0";
			std::cout << M << "\n";
		}
}
*/

/*
//1493A	--800
#include <iostream>
#include <set>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
int main ()
{
	int t, n, k;
	std::cin >> t;
	while (t--)
		{
			std::cin >> n >> k;
			std::vector<int> ans;
			for (int i = n; i > k / 2; --i)
				if (i != k)
					ans.push_back (i);
			if (k % 2 == 0)
				ans.push_back (k / 2);
			std::cout << ans.size () << "\n";
			for (const int el : ans)
				std::cout << el << " ";
			std::cout << "\n";
		}
}
*/

/*
//1487F	--2900
//THANX Rhodoks
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
class Ones
{
	std::vector<int> v;
public:
	Ones (const int n) { v.resize (n, 1); }
	Ones () {}
	Ones (const Ones &oth)
	{
		v.reserve (oth.size ());
		for (int i = 0; i < oth.size (); ++i)
			v.push_back (oth[i]);
	}
	int size () const { return v.size (); }
	int& operator [] (int i) { return v[i]; }
	int operator [] (int i) const { return v[i]; }
	bool operator < (const Ones &oth) const
	{
		if (size () != oth.size ())
			return size () < oth.size ();
		for (int i = size () - 1; i >= 0; --i)
			if (v[i] != oth[i])
				return v[i] < oth[i];
		return false;
	}
	bool operator == (const Ones &oth) const
	{
		if (size () != oth.size ())
			return false;
		for (int i = 0; i < size (); ++i)
			if (v[i] != oth[i])
				return false;
		return true;
	}
	void operator -= (const Ones &oth)
	{
		if (*this < oth)
			{
				Ones temp (oth);
				std::swap (*this, temp);
				*this -= temp;
				return;
			}
		for (int i = 0; i < oth.size (); ++i)
			{
				v[i] -= oth[i];
				if (v[i] < 0)
					{
						v[i] += 10;
						v[i + 1]--;
					}
			}
		int n = size ();
		while (n > 0 && v[n - 1] == 0) --n;
		if (n != size ())
			v.resize (n);
	}
	void in ()
	{
		std::string s;
		std::cin >> s;
		v.reserve (s.size ());
		for (const char q : s)
			v.push_back (q - '0');
		std::reverse (v.begin (), v.end ());
	}
};

int main ()
{
	Ones a;
	a.in ();
	std::vector<std::map<Ones, int>> dp (a.size () + 2);
	dp[a.size () + 1][a] = 0;

	auto upd = [&dp] (const int sz, const Ones one, const int cnt)
		{
			if (dp[sz].count (one))
				dp[sz][one] = std::min (dp[sz][one], cnt);
			else
				dp[sz][one] = cnt;
		};

	for (int i = a.size () + 1; i > 0; --i)
		{
			Ones one_i (i);
			for (auto el : dp[i])
				{
					Ones b = el.first;
					int cnt = el.second;
					while (!(b < one_i))
						{
							b -= one_i;
							cnt += i;
						}
					upd (i - 1, b, cnt);
					b -= one_i;
					cnt += i;
					upd (i - 1, b, cnt);
				}
		}
	std::cout << dp[0][Ones ()] << "\n";
}
*/

/*
//WRONG
//1487F	--2900
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
int main ()
{
	std::string S, t;
	std::cin >> S;
	int n = S.size ();
	std::vector<int> a (n, 0), s (n);
	for (int i=0;i<n;++i)
		s[i] = S[i] - '0';
	auto dec_s = [&s, &n, &a] (const int d, const int i)
		{
			a[i] += d;
			for (int j = i; j < n; ++j)
				{
					if (s[j] < d)
						{
							int k = j - 1;
							while (s[k] == 0)
								{
									s[k] = 9;
									--k;
								}
							s[k]--;
							s[j] += 10 - d;
						}
					else
						s[j] -= d;
				}
		};
	for (int i=0;i<n;++i)
		{
			if (s[i] == 0)
				continue;
			int p = n - i - 1;
			int d = s[i] - 1;
			if (d)
				dec_s (d, i);
			if (s[i] != 0)
				{
					bool can = true;
					int j = i;
					while (j < n)
						{
							if (s[j] == 0)
								{
									can = false;
									break;
								}
							else if (s[j] > 1)
								break;
							++j;
						}
					if (can)
						dec_s (1, i);
					else
						s[i + 1] += 10;
				}
		}

	std::reverse (a.begin (), a.end ());
	a.push_back (0);
	++n;


	std::set<int> order;
	for (int i=0;i<n-1;++i)
		order.insert (i);

	while (!order.empty ())
		{
			int i = *order.begin ();
			order.erase (i);

			if (a[i] == 0)
				continue;

			int price = std::abs (a[i]) * (i + 1) + std::abs (a[i + 1]) * (i + 2);
			if (i != 0)
				price += std::abs (a[0]);

			int sign = (a[i] > 0 ? 1 : -1);
			int test = std::abs (a[i + 1] + sign) * (i + 2);
			if (i != 0)
				test += std::abs (a[i] - 10 * sign) * (i + 1) + std::abs (a[0] - sign);
			else
				test += std::abs (a[i] - 11 * sign);

			if (price > test)
				{
					a[i] -= 10 * sign;
					a[i + 1] += sign;
					a[0] -= sign;
					if (i + 1 != n - 1)
						order.insert (i + 1);
					if (i > 0)
						order.insert (i - 1);
					order.insert (0);
				}
			if (i != 0 && order.empty ())
				order.insert (0);
		}


	int ans = 0;
	for (int i=0;i<n;++i)
		{
			std::cout << a[i] << "\t*\t";
			for (int j=0;j<=i;++j)
				std::cout << "1";
			std::cout << "\n";
			ans += std::abs (a[i]) * (i + 1);
		}
	std::cout << ans << "\n";
}
*/

/*
//1494A	--900
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
int main ()
{
	std::string a;
	int t, n;
	std::cin >> t;
	std::vector<std::vector<int>> tests = {
			{ 1,  1, -1},
			{ 1, -1,  1},
			{ 1, -1, -1},
			{-1,  1,  1},
			{-1, -1,  1},
			{-1,  1, -1},
	};
	while (t--)
		{
			std::cin >> a;
			n = a.size ();
			bool ok = false;
			for (const std::vector<int> &m : tests)
				{
					int sum = 0;
					for (const char q : a)
						{
							if (sum < 0)
								break;
							sum += m[q-'A'];
						}
					if (sum == 0)
						{
							ok = true;
							break;
						}
				}
			std::cout << (ok ? "YES\n" : "NO\n");
		}
}
*/

/*
//1491D	--1800
#include <iostream>
#include <vector>
int main ()
{
	int q, u, v;
	std::cin >> q;
	std::vector<int> a,b;
	while (q--)
		{
			int ui = 0, vi = 0;
			a.clear (), b.clear ();
			std::cin >> u >> v;
			if (u > v)
				{
					std::cout << "NO\n";
					continue;
				}
			while (u > 0 || v > 0)
				a.push_back (u % 2),
				ui += u % 2,
				u /= 2,
				b.push_back (v % 2),
				vi += v % 2,
				v /= 2;
			for (int i = 1; i < a.size (); ++i)
				a[i] += a[i - 1],
				b[i] += b[i - 1];
			bool ok = true;
			for (int i = 0; i < a.size () && ok; ++i)
				if (a[i] < b[i])
					ok = false;
			std::cout << (ok ? "YES\n" : "NO\n");
		}
}
*/

/*
//1491C	--1700
#include <iostream>
#include <vector>
#include <algorithm>
int main ()
{
	int t, n;
	std::vector<int> s, u;
	std::cin >> t;
	while (t--)
		{
			std::cin >> n;
			s.resize (n);
			u.clear ();
			u.resize (n, 0);
			for (int i=0;i<n;++i)
				std::cin >> s[i];
			long long ans = 0;
			for (int i=0;i<n;++i)
				{
					int inf = std::max (1, n - 1 - i);
					if (s[i] > inf)
						{
							ans += s[i] - inf;
							s[i] = inf;
						}
					while (s[i] != 1)
						{
							int j = i + s[i];
							s[i] = std::max (s[i] - 1, 1);
							++ans;
							while (j < n)
								{
									int j_new = j + s[j];
									s[j] = std::max (s[j] - 1, 1);
									if (j_new < n && u[j_new])
										j = u[j_new];
									else
										j = j_new;
								}
						}
					int j = i + 1;
					while (j < n)
						{
							if (s[j] == 1)
								{
									int k = j + 1;
									if (u[j])
										k = u[j];
									bool need_update = false;
									while (k < n && s[k] == 1)
										{
											need_update = true;
											if (u[k])
												k = u[k];
											else
												++k;
										}
									if (need_update)
										for (int p = j; p < k; ++p)
											u[p] = k;
									j = k;
								}
							else
								++j;
						}
				}
			std::cout << ans << "\n";
		}
}
*/

/*
//1491B	--1200
#include <iostream>
#include <vector>
#include <algorithm>
int main ()
{
	int t, n, u, v;
	std::vector<int> a;
	std::cin >> t;
	while (t--)
		{
			std::cin >> n >> u >> v;
			a.resize (n);
			for (int i=0;i<n;++i)
				std::cin >> a[i];

			int border = a[n-1];
			int steps = 2;
			for (int i = n-2;i>=0;i--)
				{
					if (a[i] == border)
						{
							continue;
						}
					else if (std::abs (a[i] - border) == 1)
						{
							steps = 1;
						}
					else
						{
							steps = 0;
							break;
						}
					border = a[i];
					if (border == 1000001)
						break;
				}
			int ans = 0;
			if (steps == 2)
				ans = v + std::min (v, u);
			else if (steps == 1)
				ans = std::min (v, u);
			std::cout << ans << "\n";

		}
}
*/

/*
//1492E	--2500
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
void no ()
{
	std::cout << "No\n";
	exit (0);
}
const int DEEP_OF_ERROR = 2;
int main ()
{
	int n,m;
	std::vector<std::vector<int>> s;
	std::unordered_set<int> order;
	std::vector<std::unordered_map<int, std::vector<int>>> v;
	std::vector<std::unordered_set<int>> crashed;
	std::unordered_set<int> crashed_one;
	std::vector<int> ans;
	int ans_num = 0;

	auto add_ans = [&ans, &ans_num] (const int i, const int val)
		{
			if (ans[i] != -1)
				{
					if (ans[i] != val)
						no ();
					return 0;
				}
			else
				{
					ans[i] = val;
					++ans_num;
					return 1;
				}
			return 0;
		};
	auto print_ans = [&ans, &m] ()
		{
			std::cout << "Yes\n";
			for (int i=0;i<m;++i)
				std::cout << ans[i] << " ";
			exit (0);
		};
	auto delete_from_order = [&] (std::unordered_set<int> &del)
		{
			std::queue<int> del_q;
			for (const int k : del)
				del_q.push (k);

			while (!del_q.empty ())
				{
					const int k = del_q.front ();
					del_q.pop ();
					order.erase (k);
					for (const auto el : v[k])
						{
							if (el.first == ans[k])
								continue;
							for (const int i : el.second)
								{
									crashed[i].insert (k);
									if (crashed[i].size () > DEEP_OF_ERROR)
										no ();
									if (crashed[i].size () == DEEP_OF_ERROR)
										{
											crashed_one.erase (i);
											for (const int l : order)
												//if (!crashed[i].count (l))
													{
														add_ans (l, s[i][l]);
														if (!del.count (l))
															{
																del.insert (l);
																del_q.push (l);
															}
													}
										}
									else
										{
											crashed_one.insert (i);
										}
								}
						}
				}
		};
	std::cin >> n >> m;
	s.resize (n);
	v.resize (m);
	crashed.resize (n);
	ans.resize (m, -1);
	for (int i=0;i<n;++i)
		{
			s[i].resize (m);
			for (int j=0;j<m;++j)
				{
					std::cin >> s[i][j];
					v[j][s[i][j]].push_back (i);
				}
			//dif[i].resize (n);
		}
	for (int i=0;i<m;++i)
		{
			if (v[i].size () > 1)
				order.insert (i);
			else
				add_ans (i, s[0][i]);
		}
	if (order.size () <= 2)
		{
			for (const int i : order)
				add_ans (i, s[0][i]);
			print_ans ();
		}
	std::vector<std::unordered_set<int>> dif_0 (n);
	std::vector<std::vector<int>> dif_0_num (5);
	auto short_solver = [&] ()
		{
			if (order.empty ())
				print_ans ();

			std::vector<std::unordered_set<int>> shulf;
			shulf.reserve (11);
			std::vector<int> order_v;
			order_v.reserve (order.size ());
			for (const int i : order)
				order_v.push_back (i);

			shulf.push_back ({});
			if (crashed[0].size () < DEEP_OF_ERROR)
				for (const int i : order_v)
					shulf.push_back ({i});
			if (crashed[0].size () == 0)
				{
					for (int i=0;i<order_v.size ();++i)
						for (int j=i+1;j<order_v.size ();++j)
							shulf.push_back ({order_v[i], order_v[j]});
				}

			std::vector<int> dif_num (n, 0);
			for (const auto &error_set : shulf)
				{
					std::vector<int> fine_cols;
					for (const int i : order)
						if (!error_set.count (i))
							fine_cols.push_back (i);

					bool can_be = true;
					std::unordered_map<int, std::unordered_set<int>> potential_ans;
					std::unordered_set<int> nead_check_by_error_set;
					for (int i=1;i<n;++i)
						{
							dif_num[i] = 0;
							for (const int j : fine_cols)
								if (s[0][j] != s[i][j])
									dif_num[i]++;
							if (crashed[i].size () + dif_num[i] > DEEP_OF_ERROR)
								{
									can_be = false;
									break;
								}
							else
							if (crashed[i].size () + dif_num[i] == DEEP_OF_ERROR)
								{
									for (const int j : error_set)
										potential_ans[j].insert (s[i][j]);
								}
							else
							if (crashed[i].size () + dif_num[i] == 1 && error_set.size () == 2)
								{
									nead_check_by_error_set.insert (i);
								}
						}
					if (!can_be) continue;
					for (const int j : error_set)
						{
							if (potential_ans.count (j) && potential_ans[j].size () > 1)
								{
									can_be = false;
									break;
								}
						}
					if (!can_be) continue;
					if (!nead_check_by_error_set.empty ())
						{
							std::vector<int> c;
							bool fix_el = false;
							for (const int i : error_set)
								c.push_back (i);
							if (potential_ans.count (c[0]))
								fix_el = true;

							if (fix_el)
								{
									for (const int i : nead_check_by_error_set)
										{
											int ok = 0;
											for (const int j : error_set)
												if (s[i][j] == *potential_ans[j].begin ())
													ok++;
											if (!ok)
												{
													can_be = false;
													break;
												}
										}
								}
							else
								{
									bool ok = false;
									std::vector<std::vector<int>> checks = {
											{c[0], s[*nead_check_by_error_set.begin ()][c[0]], c[1]},
											{c[1], s[*nead_check_by_error_set.begin ()][c[1]], c[0]}
									};
									for (const std::vector<int> &chk : checks)
										{
											std::unordered_set<int> oth;
											for (const int i : nead_check_by_error_set)
												{
													int equal = 0;
													if (s[i][chk[0]] != chk[1])
														oth.insert (s[i][chk[2]]);
												}
											if (oth.size () <= 1)
												{
													ok = true;
													potential_ans[chk[0]].insert (chk[1]);
													if (!oth.empty ())
														potential_ans[chk[2]].insert (*oth.begin ());
													else
														potential_ans[chk[2]].insert (s[0][chk[2]]);
													break;
												}
										}
									if (!ok) can_be = false;
								}
						}
					if (can_be)
						{
							for (const int j : fine_cols)
								add_ans (j, s[0][j]);
							for (const int j : error_set)
								if (potential_ans.count (j))
									add_ans (j, *potential_ans[j].begin ());
								else
									add_ans (j, s[0][j]);
							print_ans ();
						}
				}
			no ();
		};
	{
		bool one_err_by_row = true;
		for (int i=1;i<n;++i)
			{
				for (const int k : order)
					{
						if (s[0][k] != s[i][k])
							dif_0[i].insert (k);
					}
				if (dif_0[i].size () > 1)
					{
						one_err_by_row = false;
						if (dif_0[i].size () > 4)
							no ();
					}
				dif_0_num[dif_0[i].size ()].push_back (i);
			}
		if (one_err_by_row)
			{
				for (const int i : order)
					add_ans (i, s[0][i]);
				print_ans ();
			}
	}

	if (order.size () <= 4)
		short_solver ();

	{
		std::unordered_set<int> del;
		for (int num = 3; num <= 4; ++num)
			{
				for (const int i : dif_0_num[num])
					{
						for (const int k : order)
							{
								if (s[0][k] == s[i][k])
									{
										add_ans (k, s[0][k]);
										del.insert (k);
									}
							}
					}
			}
		delete_from_order (del);
	}

	if (order.size () <= 4)
		short_solver ();

	{
		std::unordered_set<int> del;
		bool find = false;
		for (const int i : dif_0_num[2])
			{
				if (find) break;
				for (int num = 1; num <= 2; ++num)
					{
						for (const int j : dif_0_num[num])
							{
								if (i == j)	continue;
								std::unordered_set<int> sum_dif;
								for (const int k : dif_0[i]) sum_dif.insert (k);
								for (const int k : dif_0[j]) sum_dif.insert (k);
								if (sum_dif.size () < 3) continue;

								find = true;
								for (const int k : order)
									{
										if (sum_dif.count (k))
											continue;
										add_ans (k, s[0][k]);
										del.insert (k);
									}
								break;
							}
					}
			}
		delete_from_order (del);
	}

	if (order.size () <= 4)
		short_solver ();

	// ERROR
	print_ans ();
}
*/

/*
//1491A	--800
#include <iostream>
#include <vector>
int main ()
{
	int n, q, t, x;
	std::cin >> n >> q;
	std::vector<int> a (n), v (2, 0);
	for (int i=0;i<n;++i)
		std::cin >> a[i],
		v[a[i]]++;
	while (q--)
		{
			std::cin >> t >> x;
			if (t == 1)
				{
					--x;
					v[a[x]]--;
					a[x] = 1 - a[x];
					v[a[x]]++;
				}
			else
				{
					std::cout << (v[1] < x ? 0 : 1) << "\n";
				}
		}
}
*/

/*
//1492C	--1500
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
int main ()
{
	int n, m;
	std::string s, t;
	std::cin >> n >> m >> s >> t;
	std::vector<int> a (m), b (m);
	for (int i=0,j=0;i<m;++i)
		{
			while (t[i] != s[j]) ++j;
			a[i] = j++;
		}
	for (int i=m-1,j=n-1;i>=0;--i)
		{
			while (t[i] != s[j]) --j;
			b[i] = j--;
		}
	int ans = 0;
	for (int i=1;i<m;++i)
		ans = std::max (ans, b[i] - a[i-1]);
	std::cout << ans << "\n";
}
*/

/*
//1492B	--1100
#include <iostream>
#include <vector>
#include <unordered_map>
int main ()
{
	int t, n;
	std::vector<int> p;
	std::unordered_map<int, int> m;
	std::cin >> t;
	while (t--)
		{
			std::cin >> n;
			p.resize (n);
			m.clear ();
			for (int i=0;i<n;++i)
				std::cin >> p[i],
				m[p[i]] = i;
			for (int i=n, end=n;i>0;--i)
				{
					if (m[i] > end)
						continue;
					for (int j=m[i];j<end;++j)
						std::cout << p[j] << " ";
					end = m[i];
				}
			std::cout << "\n";
		}
}
*/

/*
//1487E	--2000
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
const int inf = 1000000007;
int main ()
{
	int n[4];
	for (int i=0;i<4;++i)
		std::cin >> n[i];
	std::vector<int> a[4];
	for (int i=0;i<4;++i)
		{
			a[i].resize (n[i]);
			for (int j=0;j<n[i];++j)
				std::cin >> a[i][j];
		}
	int m[3];
	std::unordered_map<int, std::unordered_set<int>> s[3];
	for (int i=0;i<3;++i)
		{
			std::cin >> m[i];
			int x, y;
			for (int j=0;j<m[i];++j)
				std::cin >> x >> y,
				--x, --y,
				s[i][x].insert (y);
		}

	std::vector<std::pair<int, int>> v;
	for (int i=2;i>=0;i--)
		{
			v.clear ();
			v.reserve (n[i+1]);
			for (int j=0;j<n[i+1];++j)
				v.push_back (std::make_pair (a[i+1][j], j));
			std::sort (v.begin (), v.end ());
			for (int j=0;j<n[i];++j)
				{
					int val = inf;
					for (const auto el : v)
						{
							if (el.first == inf)
								break;
							if (!s[i].count (j) || !s[i][j].count (el.second))
								{
									val = a[i][j] + el.first;
									break;
								}
						}
					a[i][j] = val;
				}
		}
	std::sort (a[0].begin (), a[0].end ());
	for (int j=0;j<n[0];++j)
		if (a[0][j] != inf)
			{
				std::cout << a[0][j] << "\n";
				return 0;
			}
	std::cout << "-1\n";
}
*/

/*
//847J	--2400
//THANX 88888888: Shayan, Arpa, Batman
#include <iostream>
#include <vector>
#include <algorithm>
std::vector<int> x, y, gift;
std::vector<bool> was;
std::vector<std::vector<int>> g;
int ans;
bool dfs (const int i)
{
	if (was[i])
		return false;
	was[i] = true;

	if (gift[i] < ans)
		return true;

	for (const int j : g[i])
		{
			if (x[j] != i)
				continue ;
			const int k = y[j];
			if (dfs (k))
				{
					std::swap (x[j], y[j]);
					gift[i]--;
					gift[k]++;
					return true;
				}
		}
	return false;
}
int main ()
{
	int n, m;
	std::cin >> n >> m;
	x.resize (m);
	y.resize (m);
	was.resize (n);
	gift.resize (n);
	g.resize (n);
	for (int i=0;i<m;++i)
		{
			std::cin >> x[i] >> y[i];
			x[i]--; y[i]--;
			std::fill (was.begin (), was.end (), false);
			if (!dfs (x[i]))
				{
					std::fill (was.begin (), was.end (), false);
					if (dfs (y[i]))
						std::swap (x[i], y[i]);
					else
						++ans;
				}
			gift[x[i]]++;
			g[x[i]].push_back (i);
			g[y[i]].push_back (i);
		}

	std::cout << ans << "\n";
	for (int i=0;i<m;++i)
		std::cout << x[i] + 1 << " " << y[i] + 1 << "\n";
}
*/

/*
//1278D --2100
#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
int n;
std::vector<int> u[500001];
int was[500001];
int f (int a, int old)
{
	int res = 1;
	if (was[a])
		return 0;
	was[a] = 1;
	for (int el : u[a])
		if (el != old)
		{
			res += f (el, a);
		}
	return res;
}
int main ()
{
	std::cin >> n;
	std::vector<std::pair<int, int>> a (n);
	for (int i=0;i<n;++i)
		std::cin >> a[i].first >> a[i].second;

	std::vector<std::pair<int, int>> v;
	v.reserve (n * 2);
	for (int i = 0; i < n; ++i)
		v.push_back (std::make_pair (a[i].first, i)),
		v.push_back (std::make_pair (a[i].second, i));
	std::sort (v.begin (), v.end ());

	std::set<std::pair<int,int>> s;
	int cnt0 = 0;
	for (const auto vi : v)
	{
		if (s.count (vi))
			s.erase (vi);
		else
			{
				const int i = vi.second;
				const int r = a[i].second;

				for (const auto el : s)
					{
						if (el.first > r) break;
						++cnt0;
						if (cnt0 >= n)
							break;
						int j = el.second;
						u[i].push_back (j);
						u[j].push_back (i);
					}
				s.insert (std::make_pair (a[i].second, i));
			}
	}
	int cnt = f (0, -1);
	if (cnt == n && cnt0 == n -1)
		std::cout << "YES";
	else
		std::cout << "NO";
}
*/

/*
//1278D --2100
#include <iostream>
#include <vector>
int main ()
{
	int n;
	std::cin >> n;
	std::vector<int> l(n), r(n);
	for (int i=0;i<n;++i)
		std::cin >> l[i] >> r[i];

}
*/

/*
//1272E	--1900
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
int n;
std::vector<int> a, ans;
std::unordered_map<int, std::vector<int>> dep;
std::unordered_set<int> s;
void make (const int id, const int lv)
{
	if (ans[id] < lv && ans[id] != -1)
		return;

	ans[id] = lv;
	for (const auto el : dep[id])
		make (el, lv + 1);
}
int main ()
{
	std::cin >> n;
	a.resize (n);
	for (int i=0;i<n;++i)
		std::cin >> a[i];

	for (int i=0;i<n;++i)
		{
			const int l = i - a[i];
			const int r = i + a[i];
			if (l >= 0) dep[l].push_back (i);
			if (r < n) dep[r].push_back (i);
		}

	ans.resize (n, -1);
	for (int i=0;i<n;++i)
		{
			const int l = i - a[i];
			const int r = i + a[i];
			if (   (l >= 0 && a[i] % 2 != a[l] % 2)
					|| (r < n  && a[i] % 2 != a[r] % 2))
				ans[i] = 1,
				s.insert (i);
		}

	while (!s.empty ())
		{
			const int id = *s.begin ();
			s.erase (id);
			const int lv = ans[id] + 1;

			for (const auto it : dep[id])
				{
					if (ans[it] <= lv && ans[it] != -1)
						continue;
					ans[it] = lv;
					s.insert (it);
				}
		}

	for (const auto &el : ans)
		std::cout << el << " ";
}
*/

/*
//1237C2	--1900
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
struct type
{
	int x, y, z;
	bool operator< (const type &o) const
	{
		if (x != o.x)
			{
				return x < o.x;
			}
		else
			{
				if (y != o.y)
					return y < o.y;
				else
					return z < o.z;
			}
	}
};

std::vector<type> a;
std::vector<bool> was;
std::unordered_map<int, std::unordered_map<int, std::vector<std::pair<int, int>>>> m3;
std::unordered_map<int, std::vector<std::pair<int, int>>> m2;
std::vector<std::pair<int,int>> ans;

void make_3 ()
{
	for (auto &el0 : m3)
	for (auto &el : el0.second)
		{
			if (el.second.size () <= 1)
				continue;

			std::sort (el.second.begin (), el.second.end ());
			while (el.second.size () > 1)
				{
					int a1 = el.second.back ().second + 1;
					was[el.second.back ().second] = true;
					el.second.pop_back ();
					int a2 = el.second.back ().second + 1;
					was[el.second.back ().second] = true;
					el.second.pop_back ();
					ans.push_back (std::make_pair (a1, a2));
				}
		}
	m3.clear ();
}
void make_2 ()
{
	for (auto &el : m2)
		{
			if (el.second.size () <= 1)
				continue;

			std::sort (el.second.begin (), el.second.end ());
			while (el.second.size () > 1)
				{
					int a1 = el.second.back ().second + 1;
					was[el.second.back ().second] = true;
					el.second.pop_back ();
					int a2 = el.second.back ().second + 1;
					was[el.second.back ().second] = true;
					el.second.pop_back ();
					ans.push_back (std::make_pair (a1, a2));
				}
		}
	m2.clear ();
}
int main ()
{
	int n;
	std::cin >> n;
	a.resize (n);
	was.resize (n, false);
	ans.reserve (n / 2);
	for (int i=0;i<n;++i)
		std::cin >> a[i].x >> a[i].y >> a[i].z;

	for (int i=0;i<n;++i)
		m3[a[i].x][a[i].y].push_back (std::make_pair (a[i].z, i));
	make_3 ();

	for (int i=0;i<n;++i)
		if (!was[i])
			m3[a[i].x][a[i].z].push_back (std::make_pair (a[i].y, i));
	make_3 ();

	for (int i=0;i<n;++i)
		if (!was[i])
			m3[a[i].y][a[i].z].push_back (std::make_pair (a[i].x, i));
	make_3 ();

	for (int i=0;i<n;++i)
		if (!was[i])
			m2[a[i].x].push_back (std::make_pair (a[i].y, i));
	make_2 ();

	for (int i=0;i<n;++i)
		if (!was[i])
			m2[a[i].y].push_back (std::make_pair (a[i].x, i));
	make_2 ();

	for (int i=0;i<n;++i)
		if (!was[i])
			m2[a[i].z].push_back (std::make_pair (a[i].y, i));
	make_2 ();

	std::vector<std::pair<type, int>> v;
	v.reserve (n);
	for (int i=0;i<n;++i)
		if (!was[i])
			v.push_back (std::make_pair (a[i], i));
	std::sort (v.begin (), v.end ());
	while (v.size () > 1)
		{
			int a1 = v.back ().second + 1;
			v.pop_back ();
			int a2 = v.back ().second + 1;
			v.pop_back ();
			ans.push_back (std::make_pair (a1, a2));
		}

	for (const auto &el : ans)
		std::cout << el.first << " " << el.second << "\n";
}
*/

/*
//1492A --800
#include <iostream>
#include <algorithm>
long long f (const long long p, const long long a)
{
	if (p%a == 0)
		return 0;
	return a - p%a;
}
int main ()
{
	int t;
	std::cin >> t;
	while (t--)
		{
			long long p, a, b, c;
			std::cin >> p >> a >> b >> c;
			std::cout << std::min (f (p, a), std::min (f (p, b), f (p, c))) << "\n";
		}
}
*/

/*
//1490G	--1900
#include <iostream>
#include <vector>
#include <algorithm>
int main ()
{
	int t, n, m, x;
	std::vector<int> a;
	std::vector<long long> v;
	std::cin >> t;
	while (t--)
		{
			std::cin >> n >> m;
			a.resize (n);
			long long s = 0;
			for (int i=0;i<n;++i)
				std::cin >> a[i],
				s += a[i];
			v.resize (n);
			v[0] = a[0];
			for (int i=1;i<n;++i)
				v[i] = v[i-1] + a[i];
			for (int i=1;i<n;++i)
				v[i] = std::max (v[i-1], v[i]);
			while (m--)
				{
					long long ans = 0;
					int d = 0;
					std::cin >> x;
					if (x > v[n-1])
						{
							if (s <= 0)
								{
									std::cout << "-1 ";
									continue;
								}
							d = ((x-v[n-1]) / s + ((x-v[n-1]) % s ? 1 : 0));
							ans = (long long)n * d;
							x -= s * d;
						}
					ans += std::lower_bound (v.begin (), v.end (), x) - v.begin ();
					std::cout << ans << " ";
				}
			std::cout << "\n";
		}
}
*/

/*
//1490F --1500
#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
int main ()
{
	int t, n, a;
	std::unordered_map<int, int> m;
	std::vector<int> v;
	std::cin >> t;
	while (t--)
		{
			std::cin >> n;
			m.clear ();
			for (int i=0;i<n;++i)
				std::cin >> a, m[a]++;
			v.clear ();
			v.reserve (m.size ());
			for (const auto el : m)
				v.push_back (el.second);
			std::sort (v.begin (), v.end ());
			int ans = n;
			for (int i=0;i<v.size ();++i)
				ans = std::min (ans, n - v[i] * (static_cast<int>(v.size ()) - i));
			std::cout << ans << "\n";
		}
}
*/

/*
//1490E --1400
#include <iostream>
#include <algorithm>
#include <vector>
struct type
{
	int v;
	int i;
	bool operator<(const type b) {return v < b.v;}
} a[200000];
int main ()
{
	int t, n;
	long long b;
	std::vector<int> v;
	std::cin >> t;
	while (t--)
		{
			std::cin >> n;
			for (int i=0;i<n;++i)
				std::cin >> a[i].v, a[i].i = i + 1;
			std::sort (a, a + n);
			int j = -1;
			b = 0;
			for (int i=0;i<n - 1;++i)
				{
					b += a[i].v;
					if (b < a[i + 1].v)
						j = i;
				}
			std::cout << n - j - 1 << "\n";
			v.resize (n - j - 1);
			for (int i=j+1,k=0;i<n;++i,++k)
				v[k]=a[i].i;
			std::sort(v.begin (), v.end ());
			for (const int el : v)
				std::cout << el << " ";
			std::cout << "\n";
		}
}
*/

/*
//1490D	--1200
#include <iostream>
#include <algorithm>
int a[100], d[100];
void make (const int l, const int r, const int p)
{
	int m = std::max_element (a + l, a + r) - a;
	d[m] = p;
	if (m != l)
		make (l, m, p + 1);
	if (m + 1 != r)
		make (m + 1, r, p + 1);
}
int main ()
{
	int t, n;
	std::cin >> t;
	while (t--)
		{
			std::cin >> n;
			for (int i=0;i<n;++i)
				std::cin >> a[i];
			make (0, n, 0);
			for (int i=0;i<n;++i)
				std::cout << d[i] << " ";
			std::cout << "\n";
		}
}
*/

/*
//1490C	--1100
#include <iostream>
#include <vector>
#include <unordered_set>

int main ()
{
	int t;
	long long x;
	std::vector<long long> v;
	std::unordered_set<long long> s;
	for (int i=1;;++i)
		{
			long long l = static_cast<long long>(i) * i * i;
			v.push_back (l);
			s.insert (l);
			if (l > 1000000000000)
				break;
		}
	std::cin >> t;
	while (t--)
		{
			std::cin >> x;
			bool yes = false;
			for (int i=0;v[i]*2 <= x;++i)
				{
					long long p = x - v[i];
					if (s.count (p))
						{
							yes = true;
							break;
						}
				}
			std::cout << (yes ? "YES\n" : "NO\n");
		}
}
*/

/*
//1490B	--1000
#include <iostream>

int main ()
{
	int t, n, a, c[3], ans;
	std::cin >> t;
	while (t--)
		{
			ans = 0;
			for (int i=0;i<3;++i)
				c[i] = 0;
			std::cin >> n;
			for (int i=0;i<n;++i)
				std::cin >> a, c[a%3]++;
			for (int j = 0;j<2;++j)
				for (int i=0;i<3;++i)
					if (c[i] > n/3)
						{
							ans += c[i] - n/3;
							c[(i+1)%3] += c[i] - n/3;
							c[i] = n/3;
						}
			std::cout << ans << "\n";
		}
}
*/

/*
//1490A --800
#include <iostream>

int main ()
{
	int t, n, a[50], ans;
	std::cin >> t;
	while (t--)
		{
			std::cin >> n >> a[0];
			ans = 0;
			for (int i=1;i<n;++i)
				{
					std::cin >> a[i];
					while (a[i - 1] * 2 < a[i])
						{
							a[i - 1] *= 2;
							++ans;
						}

					int b = a[i];
					while (a[i - 1] > b * 2 )
						{
							b *= 2;
							++ans;
						}
				}
			std::cout << ans << "\n";
		}
}
*/

/*
//1487D	--1500
#include <iostream>
#include <vector>
#include <algorithm>

const int inf = 1000000000;
int main ()
{
	int t, n;
	std::cin >> t;
	std::vector<int> ans;
	ans.push_back (0);

	for (long long int i = 2; ; ++i)
		{
			if (i % 2 == 0)
				continue;
			long long int c = (i * i + 1) / 2;
			if (c <= inf)
				ans.push_back (c);
			else
				break;
		}
	while (t--)
		{
			std::cin >> n;
			auto it = std::lower_bound(ans.begin (), ans.end (), n);
			if (it == ans.end () || *it > n)
				--it;
			std::cout << it - ans.begin () << "\n";
		}
}
*/

/*
//1497C --1500
#include <iostream>

int main ()
{
	int t, n, a[100][100];
	std::cin >> t;
	while (t--)
		{
			std::cin >> n;
			for (int i = 0; i < n; ++i)
				for (int j = 0, k = i % 2; j < n; ++j)
					{
						if (i == j)
							a[i][j] = 0;
						else if (n % 2 == 0 && i + j == n - 1)
							a[i][j] = 0;
						else
							a[i][j] = (k++ % 2 == 0 ? 1 : -1);
					}
			for (int i = 0; i < n; ++i, std::cout << "\n")
				for (int j = i + 1; j < n; ++j)
					std::cout << a[i][j] << " ";
		}
}
*/

/*
//1487B --1200
#include <iostream>

int main ()
{
	int t, n, k;
	std::cin >> t;
	while (t--)
		{
			std::cin >> n >> k;
			--k;
			int ans = (k + (n % 2) * k / (n / 2)) % n + 1;
			std::cout << ans << "\n";
		}
}
*/

/*
//1487A --800
#include <iostream>
#include <vector>
#include <algorithm>

int main ()
{
	int t, n;
	std::vector<int> a;
	std::cin >> t;
	while (t--)
		{
			std::cin >> n;
			a.resize (n);
			for (int i=0;i<n;++i)
				std::cin >> a[i];
			std::sort (a.begin (), a.end ());
			int i = 1;
			for (;i<n;++i)
				if (a[i] > a[i - 1])
					break;
			std::cout << n - i << "\n";
		}
}
*/

/*
//1385E
#include <iostream>
#include <set>
int main()
{
	std::set<int> l, r;
	int t, n, m, x, y, p;
	std::cin >> t;
	while (t--)
	{
		std::cin >> n >> m;
		for (int i = 0; i < m; ++i)
		{
			std::cin >> p >> x >> y;

		}
	}
}
*/

/*
//1385D
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

std::vector<int> v[26];
std::string s;

int f(const int l, const int r, const char q)
{
	if (l + 1 == r)
		return static_cast<int> (s[l] != q);
	int l1 = (v[q - 'a'][(r + l) / 2] - v[q - 'a'][l]);
	int l2 = (v[q - 'a'][r] - v[q - 'a'][(r + l) / 2]);
	int f1 = f((r + l) / 2, r, q + 1);
	int f2 = f(l, (r + l) / 2, q + 1);
	return std::min(
		(r - l) / 2 - l1
		+ f1
		,
		(r - l) / 2 - l2
		+ f2
	);
}
int main()
{
	int t, n;
	std::cin >> t;
	for (int i = 0; i < 26; ++i)
		v[i].resize(200001);

	while (t--)
	{
		std::cin >> n >> s;

		for (int i = 1; i <= n; ++i)
		{
			for (int j = 0; j < 26; ++j)
				v[j][i] = 0;
			v[s[i - 1] - 'a'][i]++;
		}

		for (int i = 1; i <= n; ++i)
			for (int j = 0; j < 26; ++j)
				v[j][i] += v[j][i - 1];

		std::cout << f(0, n, 'a') << "\n";
	}
}
*/

/*
//1385C
#include <iostream>
int main()
{
	int t, n, a[200000];
	std::cin >> t;
	while (t--)
	{
		std::cin >> n;
		for (int i = 0; i < n; ++i)
			std::cin >> a[i];
		int i = n - 1;
		while (i > 0 && a[i] <= a[i - 1])
			--i;
		while (i > 0 && a[i] >= a[i - 1])
			--i;
		std::cout << i << "\n";
	}
}
*/

/*
//1385B
#include <iostream>
#include <vector>
int main()
{
	int t, n, a, m;
	std::cin >> t;
	while (t--)
	{
		std::cin >> n;
		std::vector<int> v(n + 1, 0);
		for (int i = 0; i < n * 2; ++i)
		{
			std::cin >> a;
			if (!v[a])
			{
				v[a] = 1;
				std::cout << a << " ";
			}
		}
		std::cout << "\n";
	}
}
*/

/*
//1385A
#include <iostream>
#include <algorithm>
int main()
{
	int t, x[3];
	std::cin >> t;
	while (t--)
	{
		for (int i = 0; i < 3; ++i)
			std::cin >> x[i];
		std::sort(x, x + 3);
		if (x[1] == x[2])
		{
			std::cout << "YES\n" << x[1] << " " << x[0] << " " << x[0] << "\n";
		}
		else
			std::cout << "NO\n";
	}
}
*/

//
/*
//1249E --1700
#include <iostream>
int n, c, a[200000], b[200000], t;
int main ()
{
	std::cin >> n >> c;
	for (int i = 1;i < n;++i)
		std::cin >> a[i];
	for (int i = 1;i < n;++i)
		std::cin >> b[i];
	int foot = 1;
	for (int i = 0;i < n;++i)
	{
		if (t + a[i] < t + b[i] + c * foot)
		{
			t += a[i];
			foot = 1;
		}
		else
		{
			t += b[i] + c * foot;
			foot = 0;
		}
		std::cout << t << " ";
	}
}
*/

/*
//1249C2  --1500
#include <iostream>
#include <vector>
int main ()
{
	std::vector<long long> v, w;
	{
		int n = 39;
		v.reserve (n);
		w.resize (n, 0);
		for (long long i = 0, d = 1;i < n;++i)
		{
			v.push_back (d);
			d *= 3;
		}
		for (int i = 1;i < n;++i)
			w[i] = w[i - 1] + v[i - 1];
	}
	int q;
	long long n;
	std::cin >> q;
	while (q--)
	{
		std::cin >> n;
		long long ans = 0;
		int it = 0;
		while (v[it] < n)
			++it;

		while (n)
		{
			if (n >= v[it] || n > w[it])
			{
				ans += v[it];
				if (n < v[it] && n > w[it])
					break;
				n -= v[it];
			}
			--it;
		}
		std::cout << ans << "\n";
	}
}
*/

/*
//1265D
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <functional>
void f (int &a, int &b)
{
	const int o = std::min (a, b);
	a -= o;
	b -= o;
}
int g (int a)
{
	return (a == 1 ? 1 : 0);
}
bool check (int a, int b, int c, int d, bool &rev)
{
	f (a, b);  f (c, d); f (b, c);
	if (b + c > 1 || a != 0 || d != 0)
		return false;
	if (b) rev = true;
	else   rev = false;
	return true;
}
void two (int a, int b, char x, char y)
{
	if (std::abs (a - b) > 1)
	{
		std::cout << "NO";
		exit (0);
	}
	std::cout << "YES\n";
	if (a < b)
	{
		std::swap (a, b);
		std::swap (x, y);
	}
	if (std::abs (a - b) == 1)
	{
		std::cout << x << " ";
		for (int i = 0; i < b; ++i)
			std::cout << y << " " << x << " ";
		exit (0);
	}
	for (int i = 0; i < b; ++i)
		std::cout << y << " " << x << " ";
	exit (0);
}
int main ()
{
	int a[4];
	bool rev;
	char b[4] = {'0','1','2','3'};
	std::cin >> a[0] >> a[1] >> a[2] >> a[3];
	if (a[0] == 0 && a[1] == 0)
		two (a[2], a[3], '2', '3');
	if (a[2] == 0 && a[3] == 0)
		two (a[0], a[1], '0', '1');
	if (a[0] == 0 && a[3] == 0)
		two (a[1], a[2], '1', '2');
	if ((a[0] && a[1] && a[2] && !a[3]) || (!a[0] && a[1] && a[2] && a[3]))
	{
		char X, Y, Z;
		int x, y, z;
		if (a[0] && a[1] && a[2] && !a[3])
			x = a[0], y = a[1], z = a[2], X = '0', Y = '1', Z = '2';
		else
			x = a[1], y = a[2], z = a[3], X = '1', Y = '2', Z = '3';
		if (std::abs (x + z - y) > 1)
		{
			std::cout << "NO";
			return 0;
		}
		if (x + z - y == -1)
		{
			std::cout << "YES\n" << Y;
			for (int i = 0;i < x;++i)
				std::cout << " " << X << " " << Y;
			for (int i = 0;i < z;++i)
				std::cout << " " << Z << " " << Y;
			return 0;
		}
	}
	else
	{
		if (!check (a[0], a[1], a[2], a[3], rev))
		{
			std::cout << "NO";
			return 0;
		}
		if (rev)
		{
			std::swap (a[0], a[3]); std::swap (b[0], b[3]);
			std::swap (a[1], a[2]); std::swap (b[1], b[2]);
		}
	}
	std::cout << "YES\n";
	int old;
	for (int i = 0; i < 4; ++i)
		if (a[i])
		{
			old = i - 1;
			break;
		}
	while (a[0] || a[1] || a[2] || a[3])
	{
		for (int i = 0; i < 4; ++i)
			if (a[i] && std::abs (i - old) == 1)
			{
				old = i;
				std::cout << b[i] << " ";
				a[i]--;
				break;
			}
	}
}
*/

/*
//1206D
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
int n, ans;
long long a[100000];
std::vector<int> cnt;
std::vector<long long> fl;
std::vector<int> u[100000];
int was[100000];
int make(int x, int num)
{
	was[x] = 1;
	for (int i = 0; i < u[x].size(); ++i)
	{
		if (was[u[x][i]] == 2)
		{
			ans = std::min(ans, num);
			return -1;
		}
		else if (!was[u[x][i]])
			make(u[x][i], num + 1);
	}
	return 0;
}
int main()
{
	std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);
	fl.push_back(1);
	cnt.push_back(0);
	while (fl.back() < 1000000000000000000)
		fl.push_back(fl.back() << 1),
		cnt.push_back(0);
	std::cin >> n;
	for (int i = 0; i < n; ++i)
	{
		std::cin >> a[i];
		if (a[i] == 0)
		{
			--i;
			--n;
		}
	}
	for (int i = 0; i < n; ++i)
	{
		std::vector<int> dl;
		for (int j = 0; j < fl.size(); ++j)
		{
			if (a[i] & fl[j])
			{
				if (cnt[j] > 1)
				{
					std::cout << 3;
					return 0;
				}
				++cnt[j];
				dl.push_back(j);
			}
		}
	}
	for (int i=0;i<n;++i)
		for (int j = 0; j < n; ++j)
			if (i != j && a[i] & a[j])
				u[i].push_back(j);
	ans = n + 1;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < fl.size(); ++j)
			was[j] = 0;
		was[i] = 2;
		for (int j = 0; j < u[i].size(); ++j)
		{
			was[u[i][j]] = 1;
			for (int k = 0; k < u[u[i][j]].size(); ++k)
			{
				if (!was[u[u[i][j]][k]])
					make(u[u[i][j]][k], 3);
			}
		}
	}
	if (ans < n + 1)
		std::cout << ans;
	else
		std::cout << -1;
}
*/

/*
//1206C
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
int n, a[200001];
int main()
{
	std::cin >> n;
	if (n % 2 == 0)
	{
		std::cout << "NO";
		return 0;
	}
	std::cout << "YES\n";
	for (int i = 0; i < n; ++i)
		if (i % 2 == 0)
			a[i] = i * 2 + 1;
		else
			a[i] = i * 2 + 2;
	for (int i = n; i < n * 2; ++i)
		if (i % 2 == 0)
			a[i] = a[i - n] - 1;
		else
			a[i] = a[i - n] + 1;
	for (int i = 0; i < n * 2; ++i)
		std::cout << a[i] << " ";
}
*/

/*
//1206B
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
int n, a[100000];
long long ans;
int main()
{
	int z0 = 0, zn = 0;
	std::cin >> n;
	for (int i = 0; i < n; ++i)
	{
		std::cin >> a[i];
		if (a[i] > 0)
			ans += a[i] - 1;
		else if (a[i] < 0)
		{
			ans += -a[i] - 1;
			++zn;
		}
		else
			++z0;
	}
	if (zn % 2 == 1)
	{
		if (z0 > 0)
			ans += z0;
		else
			ans += 2;
	}
	else
	{
		ans += z0;
	}
	std::cout << ans;
}
*/

/*
//1206A
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
int n, m, a[100], b[100];
int main()
{
	std::cin >> n;
	for (int i = 0; i < n; ++i)
		std::cin >> a[i];
	std::cin >> m;
	for (int i = 0; i < m; ++i)
		std::cin >> b[i];
	std::cout << *std::max_element(a, a + n) << " " << *std::max_element(b, b + m);
}
*/

/*
//1200D
#include <iostream>
#include <algorithm>
#include <vector>
int n, k, ans, c2[2000], r2[2000], c3[2000], r3[2000], add[2000][2000];
std::vector<int> c[2000], r[2000];
char q;
int main() {
	std::cin >> n >> k;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
		{
			std::cin >> q;
			if (q == 'B')
			{
				r[i].push_back(j);
				c[j].push_back(i);
			}
		}
	for (int i = 0; i < n; ++i)
	{
		std::sort(r[i].begin(), r[i].end());
		std::sort(c[i].begin(), c[i].end());
		if (r[i].empty())
			++ans, r2[i] = 0;
		else
			if (*r[i].rbegin() - *r[i].begin() < k)
				r2[i] = 1;
			else
				r2[i] = 0;
		if (c[i].empty())
			++ans, c2[i] = 0;
		else
			if (*c[i].rbegin() - *c[i].begin() < k)
				c2[i] = 1;
			else
				c2[i] = 0;
	}
	for (int i = 0; i < k; ++i)
		add[0][0] += c2[i] + r2[i];
	for (int i = 0; i < n - k + 1; ++i)
	{
		if (i != 0)
			add[i][0] = add[i - 1][0] - c2[i - 1] + c2[i + k - 1];
		for (int j = 1; j < n - k + 1; ++j)
		{
			add[i][j] = add[i][j - 1] - r2[j - 1] + r2[j + k - 1];
		}
	}
	int addd = 0;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			addd = std::max(addd, add[i][j]);
	std::cout << ans + addd;
}
*/

/*
//1200C
#include <iostream>
#include <algorithm>
long long n, m, sx, sy, ex, ey, gc, ng, mg, sn, en;
int q;
long long gcd(long long a, long long b) {
	while (b) {
		a %= b;
		std::swap(a, b);
	}
	return a;
}
int main() {
	std::cin >> n >> m >> q;
	while (q--) {
		std::cin >> sx >> sy >> ex >> ey;
		gc = gcd(n, m);
		ng = n / gc;
		mg = m / gc;
		sy--, ey--;

		if (sx == 1)
			sn = sy / ng;
		else
			sn = sy / mg;

		if (ex == 1)
			en = ey / ng;
		else
			en = ey / mg;

		if (sn == en)
			std::cout << "YES\n";
		else
			std::cout << "NO\n";
	}
}
*/
/*
//1200B
#include <iostream>
#include <algorithm>
int t, n, m, k, h[100];
int main() {
	std::cin >> t;
	for (int ti = 0; ti < t; ++ti)
	{
		std::cin >> n >> m >> k;
		for (int i = 0; i < n; ++i)
			std::cin >> h[i];
		int i = 0;
		while (i < n - 1)
		{
			m += h[i] - std::max((h[i + 1] - k), 0);
			if (m < 0)
				break;
			++i;
		}
		if (i == n - 1)
			std::cout << "YES\n";
		else
			std::cout << "NO\n";
	}
}
*/

/*
//1200A
#include <iostream>
int n, a[10];
int main() {
	std::cin >> n;
	for (int i = 0; i < n; ++i)
	{
		char q;
		std::cin >> q;
		if (q == 'L')
		{
			int i = 0;
			while (a[i])
				++i;
			a[i] = 1;
		}
		else if (q == 'R')
		{
			int i = 9;
			while (a[i])
				--i;
			a[i] = 1;
		}
		else
			a[q - '0'] = 0;
	}
	for (int i = 0; i < 10; ++i)
		std::cout << a[i];
}
*/
/*
//1178B	--1300
#include <iostream>
#include <string>
std::string s;
int a[1000000];
long long ans;
int main() {
	std::cin >> s;
	int v = 0, f = 0;
	for (int i = 0; i < s.size(); ++i)
	{
		if (s[i] == 'o')
		{
			if (v > 1) f += v - 1;
			a[i] = f;
			v = 0;
		}
		else
			v++;
	}
	v = 0, f = 0;
	for (int i = s.size () - 1; i >= 0; --i)
	{
		if (s[i] == 'o')
		{
			if (v > 1) f += v - 1;
			ans += 1LL * f * a[i];
			v = 0;
		}
		else
			v++;
	}
	std::cout << ans;
}
*/

/*
//1178A	--1100
#include <iostream>
#include <algorithm>
int n, x, y;
std::pair<int, int> a[100];
int main() {
	std::cin >> n;
	for (int i = 0; i < n; ++i)
		std::cin >> a[i].first,
		a[i].second = i + 1;
	std::sort(a + 1, a + n);
	x = a[0].first;
	int i, j;
	for (i = 1; i<n && a[0].first >= a[i].first * 2; ++i)
		x += a[i].first;
	j = i;
	while (j < n)
		y += a[j++].first;
	if (x <= y) {
		std::cout << 0;
		return 0;
	}
	std::cout << i << "\n";
	for (j = 0; j < i; ++j)
		std::cout << a[j].second << " ";
}
*/

/*
//1194C	--1300
#include <iostream>
#include <string>
#include <vector>
int q;
std::string s, t, p;
int main() {
	std::cin >> q;
	for (int qi = 0; qi < q; ++qi) {
		std::cin >> s >> t >> p;
		std::vector<int> ad(26, 0);
		for (int i = 0; i < p.size(); ++i)
			ad[p[i] - 'a']++;
		int it = 0, is = 0;
		while (it < t.size()) {
			if (is < s.size() && s[is] == t[it])
				++is, ++it;
			else
			{
				if (ad[t[it] - 'a']--)
				{
					++it;
				}
				else {
					break;
				}
			}
		}
		if (it == t.size() && is == s.size())
			std::cout << "YES\n";
		else
			std::cout << "NO\n";
	}
}
*/

/*
//1194B	--1300
#include <iostream>
#include <algorithm>
int n, m, q, x[50000], y[50000];
char a[400000];
int main() {
	std::cin >> q;
	for (int qi = 0; qi < q; ++qi)
	{
		std::cin >> n >> m;
		for (int i = 0; i < n; ++i)
			y[i] = 0;
		for (int i = 0; i < m; ++i)
			x[i] = 0;

		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				std::cin >> a[i*m + j],
				y[i] += static_cast<int> (a[i*m + j] == '.'),
				x[j] += static_cast<int> (a[i*m + j] == '.');

		int ans = n + m;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				ans = std::min(y[i] + x[j] - static_cast<int> (a[i*m + j] == '.'), ans);
		std::cout << ans << "\n";
	}
}
*/

/*
//1194A	--800
#include <iostream>
int n, T, x;
int main() {
	std::cin >> T;
	for (int ti = 0; ti < T; ++ti)
	{
		std::cin >> n >> x;
		std::cout << x * 2 << "\n";
	}
}
*/

/*
//1160A1
#include <iostream>
#include <vector>
#include <algorithm>

#define PRICE_FOR_HIRE 240
struct location {
	int x, y, d, p, l, h;
	int price;
};
int main() {
	int n;
	std::cin >> n;
	std::vector<std::vector<int>> way(n, std::vector<int>(n));
	std::vector<location> v;


	for (int i = 0; i < n; ++i) {
		location t;
		std::cin >> t.x >> t.y >> t.d >> t.p >> t.l >> t.h;
		t.price = t.d * t.p * (t.p + 5);
		v.emplace_back(t);
	}
	for (int i = 0; i < n; ++i)
		for (int j = i + 1; j < n; ++j)
			way[i][j] = std::abs(v[i].x - v[j].x) + std::abs(v[i].y - v[j].y);

	for (int i = 1; i < n; ++i)
		if ((2 * way[0][i] + PRICE_FOR_HIRE + v[i].d)*v[i].p < v[i].price)
			std::cout << i << "\t" << (2 * way[0][i] + PRICE_FOR_HIRE + v[i].d)*v[i].p << "\t" << v[i].price << "\n";
}
*/
/*
//1154B	--1200
#include <iostream>
#include <map>
void pu() {
	std::cout << -1;
	exit(0);
}
int n, t, a[3], d;
std::map<int, int> m;
int main() {
	std::cin >> n;
	for (int i = 0; i < n; ++i) {
		std::cin >> t;
		m[t]++;
	}
	if (m.size() > 3) pu();
	t = 0;
	for (const auto &el : m)
		a[t++] = el.first;
	if (t == 3 && a[2] - a[1] != a[1] - a[0]) pu();
	if (t == 1) d = 0;
	else if (t == 2 && (a[1] - a[0]) % 2 == 0) d = (a[1] - a[0]) / 2;
	else d = a[1] - a[0];
	std::cout << d;
}
*/

/*
//1151D	--1500
#include <iostream>
#include <algorithm>
int n, a[100007], b[100007], c[100007];
long long ans;
int main() {
	std::cin >> n;
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i] >> b[i];
		c[i] = a[i] - b[i];
	}
	//a[i]*(j-1)+b[i]*(n-j) = (a[i]-b[i])*j + n*b[i] - a[i];
	std::sort(c, c + n);
	for (int i = 0; i < n; ++i)
		ans += 1LL * (n - i) * c[i] + 1LL * n * b[i] - a[i];
	std::cout << ans;
}
*/

/*
//1153A	--1100
#include <iostream>
int n, t, s, d, ans, delt = 100007;
int main() {
	std::cin >> n >> t;
	for (int i = 1; i <= n; ++i) {
		std::cin >> s >> d;
		int ldelt = 0;
		if (t <= s)
			ldelt = s - t;
		else if ((t - s) % d == 0)
			ldelt == 0;
		else
			ldelt = d - (t - s) % d;
		if (ldelt < delt){
			delt = ldelt;
			ans = i;
		}
	}
	std::cout << ans;
}
*/

/*
//1145A	--
#include <iostream>
#include <algorithm>
int n, a[107];
int f(int l, int r) {
	bool res = true;
	if (r - l <= 1) return 1;
	for (int i = l + 1; i < r && res; ++i) {
		if (a[i] < a[i - 1])
			res = false;
	}
	if (res) return r - l;
	return std::max(f(l, (l + r) / 2), f((l + r) / 2, r));
}
int main() {
	std::cin >> n;
	for (int i = 0; i < n; ++i)
		std::cin >> a[i];
	std::cout << f(0, n);
}
*/

/*
//1144B	--1100
#include <iostream>
#include <algorithm>
int n, a[2][2007], ai[2], t, b[2], c[2];
int f(int x) {
	int res = 0;
	for (int j = 0; j < 2; ++j)
		for (int i = 0; i < ai[j] - x - 1; ++i)
			res += a[j][i];
	return res;
}
int main() {
	std::cin >> n;
	for (int i = 0; i < n; ++i) {
		std::cin >> t;
		a[t % 2][ai[t % 2]++] = t;
	}
	std::sort(a[0], a[0] + ai[0]);
	std::sort(a[1], a[1] + ai[1]);

	std::cout << f(std::min(ai[0], ai[1]));
}
*/

/*
//1144A	--900
#include <iostream>
#include <string>
int n, a[26];
std::string s;
int main() {
	std::cin >> n;
	for (int i = 0; i < n; ++i) {
		std::cin >> s;
		for (int j = 0; j < 26; ++j)
			a[j] = 0;
		for (auto q : s)
			a[q - 'a']++;
		int it = 0;
		while (it < 26 && !a[it])
			++it;
		while (it < 26 && a[it] == 1)
			++it;
		while (it < 26 && !a[it])
			++it;
		std::cout << (it == 26 ? "Yes" : "No") << "\n";
	}
}
*/

/*
//1143	--700
#include <iostream>
int n, a[200007], k, b[2];
int main() {
	std::cin >> n;
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
		b[a[i]]++;
	}
	while (b[0] && b[1]) {
		b[a[k++]]--;
	}
	std::cout << k;
}
*/

/*
//1032B	--1300
#include <iostream>
#include <string>
std::string s;
int n, a, b, c, it;
int main() {
	std::cin >> s;
	n = s.size();
	a = n / 20 + (n % 20 ? 1 : 0);
	b = n / a + (n % a ? 1 : 0);
	c = a * b - n;
	std::cout << a << " " << b << "\n";
	for (int i = 0; i < a; ++i) {
		if (i < c) {
			for (int j = 1; j < b; ++j)
				std::cout << s[it++];
			std::cout << '*';
		}
		else
			for (int j = 0; j < b; ++j)
				std::cout << s[it++];
		std::cout << "\n";
	}
}
*/

/*
//1032A	--1100
#include <iostream>
int n, k, mx, a, b[107], ans;
int main() {
	std::cin >> n >> k;
	for (int i = 0; i < n; ++i) {
		std::cin >> a;
		++b[a];
	}
	for (int i = 1; i <= 100; ++i) {
		if (b[i] > mx)
			mx = b[i];
	}
	mx = (mx % k == 0 ? mx : (mx / k) * k + k);
	for (int i = 1; i <= 100; ++i)
		if (b[i])
			ans += mx - b[i];
	std::cout << ans;
}
*/

/*
//1140B	--1200
#include <iostream>
#include <string>
int t, n;
std::string s;
int main() {
	std::cin >> t;
	for (int ti = 0; ti < t; ++ti) {
		std::cin >> n >> s;
		int l = 0, r = 0;
		while (l < n - 1 && s[l] != '>') ++l;
		while (r < n - 1 && s[n - 1 - r] != '<') ++r;
		std::cout << (l < r ? l : r) << "\n";
	}
}
*/

/*
//1140A --1000
#include <iostream>
int n, a, mx, ans;
int main() {
	std::cin >> n;
	for (int i = 1; i <= n; ++i) {
		std::cin >> a;
		if (a > mx) mx = a;
		if (i == mx) ++ans;
	}
	std::cout << ans;
}
*/

/*
//1139B --1100
#include <iostream>
#include <algorithm>
int n, a[200007];
long long ans;
int main() {
	std::cin >> n;
	for (int i = 0; i < n; ++i)
		std::cin >> a[i];
	ans = a[--n];
	while (--n >= 0) {
		a[n] = std::max(std::min(a[n], a[n + 1] - 1), 0);
		ans += a[n];
	}
	std::cout << ans;
}
*/

/*
//1139A	--700
#include <iostream>
int n, ans;
char q;
int main() {
	std::cin >> n;
	for (int i = 1; i <= n; ++i) {
		std::cin >> q;
		if ((q - '0') % 2 == 0)
			ans += i;
	}
	std::cout << ans;
	return 0;
}
*/

/*
//1141B	--1000
#include <iostream>
int n, a[200007], ans, lans;
int main() {
	std::cin >> n;
	for (int i = 0; i < n; ++i)
		std::cin >> a[i];
	for (int i = 0; i < n * 2; ++i) {
		if (a[i % n]) {
			lans += a[i % n];
		}
		else {
			if (lans > ans) ans = lans;
			lans = 0;
		}
	}
	if (lans > ans) ans = lans;
	std::cout << ans;
}
*/

/*
//1141B	--1000
#include <iostream>
#include <string>
#include <algorithm>
std::string s, t, u;
int z[500007], d, a[2], it;
void zFun() {
	int n = t.size();
	for (int i = 1, l = 0, r = 0; i < n; ++i) {
		if (i <= r)
			z[i] = std::min(r - i + 1, z[i - l]);
		while (i + z[i] < n && t[z[i]] == t[i + z[i]])
			++z[i];
		if (i + z[i] - 1 > r)
			l = i,
			r = i + z[i] - 1;
	}
}
int main() {
	std::cin >> s >> t;
	zFun();
	d = t.size();
	for (int i = 1; i <= t.size(); ++i)
		if (z[i] + i == t.size()) {
			d = i;
			break;
		}
	for (int i = 0; i < s.size(); ++i)
		a[s[i] - '0']++;
	while (a[0] && a[1]) {
		int el = t[it++] - '0';
		it %= d;
		std::cout << el;
		--a[el];
	}
	for (int i = 0; i < 2; ++i)
		while (a[i]--) std::cout << i;
	return 0;
}
*/

/*
//1141A	--1000
#include <iostream>
int n, m, ans;
int err() { std::cout << -1; return 0; }
int main() {
	std::cin >> n >> m;
	if (m % n) return err();
	m /= n;
	while (m > 1) {
		if (m % 2 == 0) {
			m /= 2;
			++ans;
		}
		else if (m % 3 == 0) {
			m /= 3;
			++ans;
		}
		else {
			return err();
		}
	}
	std::cout << ans;
}
*/

/*
//1132C	--1700
#include <iostream>
#include <vector>
#include <algorithm>
int n, q, l[5007], r[5007], a[5007], one[5007], ans, sub;
std::vector<int> v[5007];
int main() {
	std::cin >> n >> q;
	for (int i = 0; i < q; ++i) {
		std::cin >> l[i] >> r[i];
		for (int j = l[i]; j <= r[i]; ++j) {
			++a[j];
		}
	}
	for (int i = 1; i <= n; ++i) {
		if (a[i])
			++ans;
	}
	sub = ans;
	for (int i = 0; i < q; ++i) {
		for (int j = l[i]; j <= r[i]; ++j) {
			if (a[j] == 1) {
				one[i]++;
			}
			else if (a[j] == 2) {
				v[i].push_back(j);
			}
		}
		std::sort(v[i].begin(), v[i].end());
	}
	for (int i = 0; i < q - 1; ++i) {
		for (int j = i + 1; j < q; ++j) {
			std::vector<int> isec;
			std::set_intersection(
				v[i].begin(), v[i].end(),
				v[j].begin(), v[j].end(),
				std::back_inserter(isec)
			);
			sub = std::min(sub, one[i] + one[j] + (int)isec.size());
		}
	}
	ans -= sub;
	std::cout << ans;
}
*/

/*
//1131F	--1700
#include <iostream>
#include <vector>
int n, cats[150007], x, y;
std::vector<int> block[150007];
int find(int a) {
	if (a == cats[a]) return a;
	return cats[a] = find(cats[a]);
}
void unit(int x, int y) {
	x = find(x);
	y = find(y);
	if (block[x].size() < block[y].size()) std::swap(x, y);
	for (auto el : block[y])
		block[x].push_back(el);
	cats[y] = cats[x];
}
int main() {
	std::cin >> n;
	for (int i = 1; i <= n; ++i) {
		cats[i] = i;
		block[i].push_back(i);
	}
	for (int i = 0; i < n - 1; ++i) {
		std::cin >> x >> y;
		unit(x, y);
	}
	for (auto el : block[find(1)])
		std::cout << el << " ";
}
*/

/*
//WRONG
//1131F	--1700
#include <iostream>
#include <vector>
int n, x, y, z[150007], si;

struct element {
	int value;
	element *next;
	element(int value) : value(value), next(0) {}
	~element() { if (next) delete next; }
};

struct list {
	element *first, *cur;
	list() : first(0), cur(0) {}
	//~list() { if (first) delete first; }
	void push_back(int value) {
		element *temp = new element(value);
		if (!first) {
			first = temp;
			cur = temp;
		}
		else {
			cur->next = temp;
			cur = cur->next;
		}
	}
	void push_back(list *oth) {
		cur->next = oth->first;
		cur = oth->cur;
	}
	void print() {
		element *it = first;
		while (it != 0) {
			std::cout << it->value << " ";
			it = it->next;
		}
	}
};

std::vector<list*> v;
list l[150007];
int main() {
	std::cin >> n;
	for (int i = 0; i < n - 1; ++i) {
		std::cin >> x >> y;
		if (!z[x] && !z[y]) {
			int it = ++si;
			v.push_back(&l[si]);
			v[it - 1]->push_back(x);
			v[it - 1]->push_back(y);
			z[x] = it;
			z[y] = it;
		}
		else if (!z[y]) {
			int it = z[x];
			v[it - 1]->push_back(y);
			z[y] = it;
		}
		else if (!z[x]) {
			int it = z[y];
			v[it - 1]->push_back(x);
			z[x] = it;
		}
		else {
			v[z[x] - 1]->push_back(v[z[y] - 1]);
			v[z[y] - 1] = v[z[x] - 1];
			//z[y] = z[x];
		}
	}
	v[0]->print();
	v[0]->first->~element();
}
*/

/*
//1118C	--1700
#include <iostream>
int n, t, a[1007], ans[21][21];
int main() {
	std::cin >> n;
	for (int i = 0; i < n*n; ++i) {
		std::cin >> t;
		++a[t];
	}
	if (n == 1) {
		std::cout << "YES\n" << t;
		return 0;
	}
	int x = 0, y = 0;
	for (int i = 1; i <= 1000 && y < n / 2; ++i) {
		while (a[i] >= 4 && y < n / 2) {
			ans[y][x] = i;
			ans[y][n - 1 - x] = i;
			ans[n - 1 - y][x] = i;
			ans[n - 1 - y][n - 1 - x] = i;
			a[i] -= 4;
			++x;
			if (x == n / 2) {
				x = 0;
				++y;
			}
		}
	}
	if (y != n / 2) {
		std::cout << "NO";
		return 0;
	}
	if (n % 2) {
		int it = 0;
		for (int i = 1; i <= 1000 && it < n / 2; ++i) {
			while (a[i] >= 2 && it < n / 2) {
				ans[n / 2][it] = i;
				ans[n / 2][n - 1 - it] = i;
				a[i] -= 2;
				++it;
			}
		}
		if (it != n / 2) {
			std::cout << "NO";
			return 0;
		}
		it = 0;
		for (int i = 1; i <= 1000 && it < n / 2; ++i) {
			while (a[i] >= 2 && it < n / 2) {
				ans[it][n / 2] = i;
				ans[n - 1 - it][n / 2] = i;
				a[i] -= 2;
				++it;
			}
		}
		if (it != n / 2) {
			std::cout << "NO";
			return 0;
		}
		for (int i = 1; i <= 1000; ++i) {
			if (a[i]) {
				ans[n / 2][n / 2] = i;
				--a[i];
				break;
			}
		}
	}
	std::cout << "YES\n";
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			std::cout << ans[i][j] << " ";
		}
		std::cout << "\n";
	}
}
*/

/*
//1137A	--1600
#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
int n, m, a[1007][1007], ans[1007][1007];
std::set<int> was_r[1007], was_c[1007];
std::vector<int> v_r[1007], v_c[1007];
int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	std::cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			std::cin >> a[i][j];

			if (!was_r[i].count(a[i][j])) {
				v_r[i].push_back(a[i][j]);
				was_r[i].insert(a[i][j]);
			}
			if (!was_c[j].count(a[i][j])) {
				v_c[j].push_back(a[i][j]);
				was_c[j].insert(a[i][j]);
			}
		}
	}

	for (int i = 0; i < n; ++i)
		std::sort(v_r[i].begin(), v_r[i].end());
	for (int i = 0; i < m; ++i)
		std::sort(v_c[i].begin(), v_c[i].end());

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			int r_ind = std::find(v_r[i].begin(), v_r[i].end(), a[i][j]) - v_r[i].begin() + 1;
			int c_ind = std::find(v_c[j].begin(), v_c[j].end(), a[i][j]) - v_c[j].begin() + 1;
			int ind = std::max(r_ind, c_ind);

			ans[i][j] = std::max(v_r[i].size() - r_ind, v_c[j].size() - c_ind) + ind;
			std::cout << ans[i][j] << " ";
		}
		std::cout << "\n";
	}
}
*/

/*
//1136C	--1500
#include <iostream>
#include <map>
int n, m, a[507][507], b[507][507];
int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	std::cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			std::cin >> a[i][j];
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			std::cin >> b[i][j];
		}
	}
	for (int i = 0; i < m + n; ++i) {
		std::map<int, int> ma, mb;
		for (int j = 0; j < m + n; ++j) {
			int x = i - j;
			int y = j;
			if (x >= 0 && x < n && y < m) {
				++ma[a[x][y]];
				++mb[b[x][y]];
			}
		}
		for (const auto &el : ma) {
			if (el.second != mb[el.first]) {
				std::cout << "NO";
				return 0;
			}
		}
	}
	std::cout << "YES";
	return 0;
}
*/

/*
//1136B	--1000
#include <iostream>
#include <algorithm>
int n, k;
int main() {
	std::cin >> n >> k;
	std::cout << std::min(k - 1, n - k) + n - 1 + n + 1 + n;
	return 0;
}
*/

/*
//1136A	--700
#include <iostream>
int n, l, r[107], k, it;
int main() {
	std::cin >> n;
	for (int i = 0; i < n; ++i) {
		std::cin >> l >> r[i];
	}
	std::cin >> k;
	while (it < n && r[it] < k)
		++it;
	std::cout << n - it;
}
*/

/*
//1133F2	--2200
#include <iostream>
#include <vector>
#include <set>
int n, m, D, v, u, gr;
std::vector<int> w[200007];
std::vector< std::vector< std::pair<int, int> > > x;
std::set<int> s;
bool was[200007];
void make_graph(int it, int &gr) {
	if (was[it]) return;
	was[it] = true;
	for (int i = 0; i < w[it].size(); ++i) {
		int el = w[it][i];
		if (!was[el]) {
			x[gr].push_back({ it, el });
			make_graph(el, gr);
		}
	}
}
void make(int it) {
	if (was[it]) return;
	was[it] = true;
	for (int i = 0; i < w[it].size(); ++i) {
		int el = w[it][i];
		if (!was[el]) {
			std::cout << it << " " << el << "\n";
			make(el);
		}
	}
}
int main() {
	std::cin >> n >> m >> D;
	for (int i = 0; i < m; ++i) {
		std::cin >> u >> v;
		w[u].push_back(v);
		w[v].push_back(u);
	}

	was[1] = true;
	for (int i = 0; i < w[1].size(); ++i) {
		int el = w[1][i];
		if (!was[el]) {
			x.push_back({});
			x[gr].push_back({ 1, el });
			s.insert(el);
			make_graph(el, gr);
			++gr;
		}
	}
	if (x.size() > D || D > w[1].size()) {
		std::cout << "NO";
		return 0;
	}
	std::cout << "YES\n";
	std::vector<int> w1 = w[1];
	for (int i = 1; i <= n; ++i)
		w[i].clear();

	for (int i = 0, j = D - x.size(); i < w1.size() && j > 0; ++i) {
		int el = w1[i];
		if (!s.count(el)) {
			--j;
			w[1].push_back(el);
			w[el].push_back(1);
		}
	}
	for (int i = 0; i < gr; ++i) {
		for (int j = 0; j < x[i].size(); ++j) {
			u = x[i][j].first;
			v = x[i][j].second;

			w[u].push_back(v);
			w[v].push_back(u);
		}
	}

	int head = 1;
	for (int i = 1; i <= n; ++i)
		was[i] = false;
	was[head] = true;
	for (int i = 0; i < w[head].size(); ++i) {
		was[w[head][i]] = true;
		std::cout << head << " " << w[head][i] << "\n";
	}
	for (int i = 0; i < w[head].size(); ++i) {
		was[w[head][i]] = false;
		make(w[head][i]);
	}
}
*/

/*
//1133F1	--1600
#include <iostream>
#include <vector>
int n, m, u, v, head, headCnt;
std::vector<int> w[200007];
bool was[200007];
void make(int it) {
	if (was[it]) return;
	was[it] = true;
	for (int i = 0; i < w[it].size(); ++i) {
		int el = w[it][i];
		if (!was[el]) {
			std::cout << it << " " << el << "\n";
			make(el);
		}
	}
}
int main() {
	std::cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		std::cin >> u >> v;
		w[u].push_back(v);
		w[v].push_back(u);
	}
	for (int i = 1; i <= n; ++i) {
		if (w[i].size() > headCnt) {
			head = i;
			headCnt = w[i].size();
		}
	}
	was[head] = true;
	for (int i = 0; i < w[head].size(); ++i) {
		was[w[head][i]] = true;
		std::cout << head << " " << w[head][i] << "\n";
	}
	for (int i = 0; i < w[head].size(); ++i) {
		was[w[head][i]] = false;
		make(w[head][i]);
	}
}
*/

/*
//1133D	--1500
#include <iostream>
#include <map>
#include <algorithm>
int n, a[200007], b[200007], ans, add;
std::map< std::pair<int, int>, int > m;
template <class T>
T nod(T a, T b) {
	while (a && b)
		if (a >= b) a %= b;
		else b %= a;
	return a | b;
}
int main() {
	std::cin >> n;
	for (int i = 0; i < n; ++i)
		std::cin >> a[i];
	for (int i = 0; i < n; ++i)
		std::cin >> b[i];
	for (int i = 0; i < n; ++i) {
		if (a[i]) {
			int nd = nod(std::abs(a[i]), std::abs(b[i]));
			if (a[i] < 0) a[i] *= -1, b[i] *= -1;
			++m[{a[i] / nd, b[i] / nd}];
		}
		else {
			if (!b[i])
				++add;
		}
	}
	for (const auto &el : m) {
		ans = std::max(ans, el.second);
	}
	std::cout << ans + add;
}
*/

/*
//1138A	--900
#include <iostream>
#include <algorithm>
int n, ans, t, ot, cur, ocur;
int main() {
	std::cin >> n;
	for (int i = 0; i < n; ++i) {
		std::cin >> t;
		if (t == ot) {
			++cur;
		}
		else {
			ot = t;
			ans = std::max(ans, std::min(ocur, cur));
			ocur = cur;
			cur = 1;
		}
	}
	ans = std::max(ans, std::min(ocur, cur));
	std::cout << ans * 2;
}
*/

/*
//1133C	--1300
#include <iostream>
#include <map>
#include <algorithm>
std::map<int, int> m;
int n, a, ans, lans;
const int val = 5;
int main() {
	std::cin >> n;
	for (int i = 0; i < n; ++i) {
		std::cin >> a;
		++m[a];
	}
	auto it = m.begin();
	auto old = m.begin();
	while (it != m.end()) {
		while (it->first - old->first > val) {
			ans = std::max(ans, lans);
			lans -= old->second;
			++old;
		}

		lans += it->second;
		++it;
	}
	ans = std::max(ans, lans);
	std::cout << ans;
}
*/

/*
//1133B	--1300
#include <iostream>
#include <algorithm>
int n, k, d, a[107], ans;
int main() {
	std::cin >> n >> k;
	for (int i = 0; i < n; ++i) {
		std::cin >> d;
		a[d % k]++;
	}
	if (k % 2 == 0) a[k / 2] /= 2;
	ans = a[0] / 2;
	for (int i = 1; i <= k / 2; ++i) {
		ans += std::min(a[i], a[k - i]);
	}
	std::cout << ans * 2;
}
*/

/*
//1133A	--1000
#include <iostream>
int h1, h2, m1, m2, mid;
char q;
void f(int a) {
	if (a < 10)
		std::cout << "0";
	std::cout << a;
}
int main() {
	std::cin >> h1 >> q >> m1 >> h2 >> q >> m2;
	mid = (h2 * 60 + m2 + h1 * 60 + m1) / 2;
	f(mid / 60);
	std::cout << ":";
	f(mid % 60);
}
*/

/*
//1114C	--1700
#include <iostream>
#include <algorithm>
long long n, b, ans = 1000000000000000000LL;
int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	std::cin >> n >> b;
	for (long long i = 2; i <= b; ++i) {
		if (1LL * i * i > b) i = b;
		long long cnt = 0;
		while (b % i == 0) {
			b /= i;
			++cnt;
		}
		if (!cnt) continue;
		long long a = 1, x = 0;
		while (a <= n / i) {
			a *= i;
			x += n / a;
		}
		ans = std::min(ans, x / cnt);
	}
	std::cout << ans;
}
*/

/*
//1132B
#include <iostream>
#include <algorithm>
int n, a[300007], m, q;
long long sm;
int main() {
	std::cin >> n;
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
		sm += a[i];
	}
	std::sort(a, a + n, std::greater<int>());
	std::cin >> m;
	for (int i = 0; i < m; ++i) {
		std::cin >> q;
		std::cout << sm - a[q - 1] << "\n";
	}
}
*/

/*
//1232A
#include <iostream>
int cnt[4];
int main() {
	for (int i = 0; i < 4; ++i)
		std::cin >> cnt[i];
	if (cnt[0] || cnt[3]) {
		std::cout << (cnt[0] == cnt[3] ? 1 : 0);
	}
	else {
		std::cout << (!cnt[2] ? 1 : 0);
	}
}
*/

/*
//1221B
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
int n, a;
std::map<int, int> m, ans;
std::vector<int> v;
int main() {
	std::cin >> n;
	for (int i = 0; i < n; ++i) {
		std::cin >> a;
		++m[a];
	}
	for (auto el : m) {
		v.push_back(el.first);
	}
	for (int i = 0; i < v.size(); ++i) {
		if (m.count(v[i]) > 1)
			ans[v[i] * 2] = m[v[i]] / 2;
		for (int j = i + 1; j < v.size(); ++j) {
			ans[v[i] + v[j]] += std::min(m[v[i]], m[v[j]]);
		}
	}
	a = 0;
	for (const auto &el : ans) {
		if (el.second > a)
			a = el.second;
	}
	std::cout << a;
}
*/

/*
//1121A
#include <iostream>
#include <vector>
#include <algorithm>
std::vector<int> v[107];
int ans;
int main ()
{
	int n = 0, m = 0, k = 0, p[107], s[107], c[107];
	std::cin >> n >> m >> k;

	for (int i = 1; i <= n; ++i)
		std::cin >> p[i];

	for (int i = 1; i <= n; ++i) {
		std::cin >> s[i];
		v[s[i]].push_back(p[i]);
	}
	for (int i = 1; i <= n; ++i) {
		std::sort(v[i].begin(), v[i].end(), std::greater<int>());
	}


	for (int i = 0; i < k; ++i) {
		std::cin >> c[i];
		if (v[s[c[i]]][0] != p[c[i]])
			++ans;
	}
	std::cout << ans;
}
*/

/*
//1111C	--1700
#include <iostream>
#include <algorithm>
int n, k, A, B, n2[31], a[100007];
long long ans;
long long destroy(int l, int r, int al, int ar) {
	if (al == ar) return A;
	if (l == r) return 1LL * B * (ar - al);

	int mid = l - 1 + (r - l + 1) / 2;
	int amid = al;
	while (amid < ar && a[amid] <= mid)
		++amid;

	long long L = destroy(l, mid, al, amid);
	long long R = destroy(mid + 1, r, amid, ar);

	if (1LL * (ar - al) * (r - l + 1) * B <= L + R) {
		return 1LL * (ar - al) * (r - l + 1) * B;
	}
	return L + R;
}
int main() {
	n2[0] = 1;
	for (int i = 1; i < 31; ++i)
		n2[i] = n2[i - 1] * 2;

	std::cin >> n >> k >> A >> B;
	for (int i = 0; i < k; ++i)
		std::cin >> a[i];
	std::sort(a, a + k);
	ans = destroy(1, n2[n], 0, k);
	std::cout << ans;
}
*/

/*
//1091D	--1700
#include <iostream>
const int inf = 998244353;
int n;
long long ans, nf[1000007];

int mul(int a, int b) {
	return 1LL * a * b % inf;
}

int main() {
	std::cin >> n;
	nf[n] = 1;
	for (int i = n; i > 0; --i)
		nf[i - 1] = mul(nf[i], i);

	ans = nf[0];
	for (int i = 1; i < n - 1; ++i)
		ans = (ans + mul(i, mul(nf[n - i], n - i - 1))) % inf;

	std::cout << ans;
}
*/

/*
//1085D	--1700
#include <iostream>
int n, s, v[100007], a, b, cnt;
double ans;
int main() {
	std::cin >> n >> s;
	for (int i = 1; i < n; ++i) {
		std::cin >> a >> b;
		++v[a];
		++v[b];
	}
	for (int i = 1; i <= n; ++i) {
		if (v[i] == 1) {
			++cnt;
		}
	}
	ans = 1.0 * s / cnt * 2;
	std::cout.precision(12);
	std::cout << ans;
}
*/

/*
//1061C	--1700
#include <iostream>
#include <vector>
#include <algorithm>
const int inf = 1000000007;
int n, a, dp[1000007];
long long ans;
int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	std::cin >> n;
	dp[0] = 1;
	for (int i = 1; i <= n; ++i) {
		std::cin >> a;
		std::vector<int> v, v1;
		for (int j = 1; j*j <= a; ++j) {
			if (a % j == 0) {
				v1.push_back(j);
				if (j * j != a)
					v.push_back(a / j);
			}
		}

		std::reverse(v1.begin(), v1.end());
		v.insert(v.end(), v1.begin(), v1.end());
		for (auto el : v) {
			dp[el] += dp[el - 1];
			dp[el] %= inf;
			ans += dp[el - 1];
			ans %= inf;
		}
	}
	std::cout << ans;
}
*/

/*
//1057A	--1700
#include <iostream>
#include <vector>
int n, p[200007];
std::vector<int> v;
int main() {
	std::cin >> n;
	for (int i = 2; i <= n; ++i) {
		std::cin >> p[i];
	}

	int it = n;
	while (it != 1) {
		v.push_back(it);
		it = p[it];
	}
	v.push_back(it);

	for (int i=v.size()-1;i>=0;--i)
		std::cout << v[i] << " ";

	return 0;
}
*/

/*
//1051D	--1700
#include <iostream>
const int inf = 998244353;
int n, k, dp[1007][2007][4], ans;
int cntAdd(int a, int b) {
	int fl = 10 * b + a;
	switch (fl) {
	case 0:		return 0;
	case 1:		return 1;
	case 2:		return 1;
	case 3:		return 1;
	case 10:	return 0;
	case 11:	return 0;
	case 12:	return 2;
	case 13:	return 0;
	case 20:	return 0;
	case 21:	return 2;
	case 22:	return 0;
	case 23:	return 0;
	case 30:	return 1;
	case 31:	return 1;
	case 32:	return 1;
	case 33:	return 0;
	}
	return 0;
}
int main() {
	std::cin >> n >> k;
	for (int fl = 0; fl < 4; ++fl)
		dp[1][0][fl] = 1;

	for (int i = 1; i < n; ++i) {
		for (int j = 0; j < k + 1; ++j) {
			for (int fl = 0; fl < 4; ++fl) {
				for (int fln = 0; fln < 4; ++fln) {
					dp[i + 1][j + cntAdd(fl, fln)][fln] = (
						dp[i + 1][j + cntAdd(fl, fln)][fln] +
						dp[i][j][fl]
					) % inf;
				}
			}
		}
	}

	for (int fl = 0; fl < 4; ++fl) {
		int add = cntAdd(fl, fl ^ 3);
		if (k >= add)
			ans = (ans + dp[n][k - add][fl]) % inf;
	}
	std::cout << ans;
}
*/

/*
//1045I	--1700
#include <iostream>
#include <string>
#include <map>
int N, alf[26];
long long ans;
std::string s;
std::map<int, int> m[27];
int main() {
	std::cin >> N;
	for (int i = 0; i < N; ++i) {
		std::cin >> s;

		for (int j = 0; j < 26; ++j)
			alf[j] = 0;

		for (int j = 0; j < s.size(); ++j) {
			++alf[s[j] - 'a'];
		}

		int odd = 0, flag = 0;
		for (int j = 0; j < 26; ++j)
			if (alf[j] % 2) {
				++odd;
				flag += 1 << j;
			}

		m[odd][flag]++;
	}

	if (m[0].size())
		ans = 1LL * (m[0][0] - 1) * m[0][0] / 2LL;

	for (int odd = 1; odd < 26; ++odd) {
		for (auto el : m[odd]) {
			int flag = el.first;
			int cnt = el.second;

			ans += 1LL * (cnt - 1) * cnt / 2LL;

			for (int i = 0; i < 26; ++i) {
				if (flag & (1 << i)) {
					if (m[odd - 1].count(flag - (1 << i))) {
						ans += 1LL * cnt * m[odd - 1][flag - (1 << i)];
					}
				}
			}
		}
	}
	std::cout << ans;
	return 0;
}
*/

/*
//1044A	--1700
#include <iostream>
#include <map>
const int inf = 1000000000;
int n, m, x, x1, x2, y, ans;
std::map<int, int> a, b;
int main() {
	std::cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		std::cin >> x;
		a[x]++;
	}
	for (int i = 0; i < m; ++i) {
		std::cin >> x1 >> x2 >> y;
		if (x1 == 1) {
			b[x2]++;
		}
	}
	auto ita = a.begin();
	auto itb = b.begin();
	while (itb != b.end()) {
		if (ita == a.end()) {
			if (itb->first == inf) {
				ans += itb->second;
			}
			++itb;
		}
		else {
			if (ita->first <= itb->first) {
				++ans;
				++ita;
				if (!--itb->second)
					++itb;
			}
			else {
				++itb;
			}
		}
	}

	std::cout << ans;
	return 0;
}
*/

/*
//1043D	--1700
#include <iostream>
#include <algorithm>
int n, m, a[10][100000], per[100007], mn[10000];
long long ans;
int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	std::cin >> n >> m;
	for (int i = 0; i < m; ++i)
		for (int j = 0; j < n; ++j) {
			std::cin >> a[i][j];
			--a[i][j];
		}
	for (int i = 0; i < n; ++i)
		per[a[0][i]] = i;

	for (int i = 0; i < m; ++i)
		for (int j = 0; j < n; ++j)
			a[i][j] = per[a[i][j]];

	for (int i = 0; i < n; ++i)
		mn[i] = n;

	for (int i = 0; i < m; ++i) {
		int cur = 0;
		for (int j = 0; j < n; ++j) {
			if (cur < j) ++cur;

			while (cur < n - 1 && a[i][cur + 1] == a[i][cur] + 1) ++cur;

			mn[a[i][j]] = std::min(mn[a[i][j]], a[i][cur]);
		}
	}

	int it = 0;
	while (it < n) {
		int cur = mn[it] - it + 1;
		ans += 1LL * (cur + 1)*cur / 2LL;
		it = mn[it] + 1;
	}
	std::cout << ans;
}
*/

/*
//1034A	--1700
#include <iostream>
#include <algorithm>
const int inf = 15000007;
int n, a[inf], d[inf], nd, cnt[inf], ans;

template <class T>
T nod(T a, T b) {
	while (a && b)
		if (a >= b) a %= b;
		else b %= a;
	return a | b;
}

int main() {
	std::cin >> n;
	for (int i = 2; i < inf; ++i)
		if (!d[i])
			for (int j = i; j < inf; j = j + i)
				if (!d[j])
					d[j] = i;

	for (int i = 0; i < n; ++i)
		std::cin >> a[i];

	nd = a[0];
	for (int i = 1; i < n; ++i)
		nd = nod(nd, a[i]);
	for (int i = 0; i < n; ++i)
		a[i] /= nd;

	for (int i = 0; i < n; ++i) {
		for (int x = a[i]; x > 1;) {
			int div = d[x];
			while (x % div == 0) x /= div;
			cnt[div]++;
		}
	}
	for (int i = 0; i < inf; ++i)
		if (cnt[i] > ans)
			ans = cnt[i];

	std::cout << (ans ? n - ans : -1);
}
*/

/*
//1130D	--1800
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int n, m, a, b;
vector<int> v[5007];
int main() {
	IOS;
	std::cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		std::cin >> a >> b;
		v[--a].push_back(--b);
	}
	for (int i = 0; i < n; ++i) {
		if (!v[i].size())
			continue;
		sort(v[i].begin(), v[i].end(), [i](int a, int b) {
			return ((a + n - i) % n) > ((b + n - i) % n);
		});
	}
	for (int i = 0; i < n; ++i) {
		int ans = 0;
		for (int j = i, k = 0; k < n; j = (j + 1) % n, ++k) {
			if (!v[j].size())
				continue;
			int lans = (j + n - i) % n +
				(v[j][v[j].size() - 1] + n - j) % n +
				(v[j].size() - 1) * n;
			if (lans > ans)
				ans = lans;
		}
		std::cout << ans << " ";
	}

	return 0;
}
*/

/*
//1130C
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int n, r1, c1, r2, c2, ans = 1000000000;
string s[100];
int *w1, *w2;
vector<int> v1, v2;

void make(int x, int y, int *w, vector<int> &v) {
	if (x < 0 || y < 0 || x >= n || y >= n || w[x*n + y] || s[x][y] == '1')
		return;

	w[x*n + y] = 1;
	v.push_back(x*n + y);

	make(x + 1, y, w, v);
	make(x - 1, y, w, v);
	make(x, y + 1, w, v);
	make(x, y - 1, w, v);
}

int main() {
	IOS;
	std::cin >> n >> r1 >> c1 >> r2 >> c2;
	--r1; --c1; --r2; --c2;
	for (int i = 0; i < n; ++i)
		std::cin >> s[i];
	w1 = new int[n * n];
	w2 = new int[n * n];
	for (int i = 0; i < n*n; ++i) {
		w1[i] = 0;
		w2[i] = 0;
	}

	make(r1, c1, w1, v1);
	if (w1[r2*n + c2]) {
		cout << 0;
		delete[] w1;
		delete[] w2;
		return 0;
	}
	make(r2, c2, w2, v2);

	for (auto x : v1) {
		for (auto y : v2) {
			if ((x / n - y / n)*(x / n - y / n) + (x % n - y % n)*(x % n - y % n) < ans)
				ans = (x / n - y / n)*(x / n - y / n) + (x % n - y % n)*(x % n - y % n);
		}
	}

	cout << ans;
	delete[] w1;
	delete[] w2;
	return 0;
}
*/

/*
//1130B
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int n, a[100007][2], t, x = 1, y = 1;
long long ans;
int main() {
	IOS;
	std::cin >> n;
	for (int i = 1; i <= n * 2; ++i) {
		std::cin >> t;
		(a[t][0] ? a[t][1] : a[t][0]) = i;
	}
	for (int i = 1; i <= n; ++i) {
		if (abs(x - a[i][0]) + abs(y - a[i][1]) < abs(x - a[i][1]) + abs(y - a[i][0])) {
			ans += abs(x - a[i][0]);
			x = a[i][0];
			ans += abs(y - a[i][1]);
			y = a[i][1];
		}
		else {
			ans += abs(x - a[i][1]);
			x = a[i][1];
			ans += abs(y - a[i][0]);
			y = a[i][0];
		}
	}
	std::cout << ans;
	return 0;
}
*/


/*
//1130A
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int n, a, d[2];
int main() {
	IOS;
	std::cin >> n;
	for (int i = 0; i < n; ++i) {
		std::cin >> a;
		if (a > 0) d[1]++;
		else if (a < 0) d[0]++;
	}
	if (d[1] >= n / 2 + (n % 2 ? 1 : 0)) {
		std::cout << 1;
	}
	else if (d[0] >= n / 2 + (n % 2 ? 1 : 0)) {
		std::cout << -1;
	}
	else
		std::cout << 0;
	return 0;
}
*/

/*
//1131C	--1200
#include <iostream>
#include <algorithm>
#include <deque>
int n, a[100];
std::deque<int> deq;
int main() {
	std::cin >> n;
	for (int i = 0; i < n; ++i)
		std::cin >> a[i];
	std::sort(a, a + n);
	for (int i = 0; i < n; ++i) {
		if (i % 2) deq.push_front(a[i]);
		else deq.push_back(a[i]);
	}
	for (auto el : deq) {
		std::cout << el << " ";
	}
}
*/

/*
//1131B	--1300
#include <iostream>
#include <algorithm>
int n, a, b, A, B, ans;
int main() {
	std::cin >> n;
	for (int i = 0; i < n; ++i) {
		std::cin >> a >> b;
		if (a != A || b != B) {
			ans += std::max(std::min(a, b) - std::max(A, B) + (A == B ? 0 : 1), 0);
			A = a;
			B = b;
		}
	}
	++ans;
	std::cout << ans;
}
*/

/*
//1131A --800
#include <iostream>
int w1, h1, w2, h2;
int main() {
	std::cin >> w1 >> h1 >> w2 >> h2;
	std::cout << w1 + 2 + h1 * 2 + (w1 - w2) + h2 * 2 + w2 + 2;
}
*/

/*
//1031C	--1700
#include <iostream>
#include <vector>
std::vector<int> p, q;
long long a, b, x;
void print(std::vector<int> &v) {
	std::cout << v.size() << "\n";
	for (auto el : v)
		std::cout << el << " ";
}
int main() {
	std::cin >> a >> b;

	while (x * (x + 1) / 2 < a + b)
		++x;
	if (x * (x + 1) / 2 > a + b)
		--x;

	for (int i = x; i > 0; --i) {
		if (a >= i) {
			a -= i;
			p.push_back(i);
		}
		else {
			b -= i;
			q.push_back(i);
		}
	}

	print(p);
	std::cout << "\n";
	print(q);

	return 0;
}
*/

/*
//1030D	--1700
#include <iostream>
long long n, m, k, a, b, c;

template <class T>
T nod(T a, T b) {
	while (a && b)
		if (a >= b) a %= b;
		else b %= a;
	return a | b;
}

int main() {
	std::cin >> n >> m >> k;
	c = nod(n*m, k);
	a = n * m / c;
	b = k / c;

	if (b == 1)
		a *= 2;

	if (b > 2 || a > n * m) {
		std::cout << "NO";
		return 0;
	}

	std::cout << "YES\n0 0\n";
	//a == x[0]*y[1] - x[1]*y[0];
	if (n >= m) {
		long long Y = a / n + (a % n ? 1 : 0);
		long long X = a / Y + (a % Y ? 1 : 0);

		a = X * Y - a;
		std::cout << X << " " << a << "\n" << (a ? 1 : 0) << " " << Y;
	}
	else {
		long long X = a / m + (a % m ? 1 : 0);
		long long Y = a / X + (a % X ? 1 : 0);

		a = X * Y - a;
		std::cout << X << " " << a << "\n" << (a ? 1 : 0) << " " << Y;
	}

	return 0;
}
*/

/*
//993A	--1700
#include <iostream>
#include <algorithm>
int x[4][2], y[4][2];
bool check() {
	int u, d, l, r, U, D, L, R, LX, LY, Ld;

	U = std::max(std::max(y[0][1], y[1][1]), std::max(y[2][1], y[3][1]));
	D = std::min(std::min(y[0][1], y[1][1]), std::min(y[2][1], y[3][1]));
	LY = (U + D) / 2;

	R = std::max(std::max(x[0][1], x[1][1]), std::max(x[2][1], x[3][1]));
	L = std::min(std::min(x[0][1], x[1][1]), std::min(x[2][1], x[3][1]));
	LX = (R + L) / 2;

	Ld = (U - D) / 2;


	u = std::max(y[0][0], y[2][0]) - LY;
	d = std::min(y[0][0], y[2][0]) - LY;
	r = std::max(x[0][0], x[2][0]) - LX;
	l = std::min(x[0][0], x[2][0]) - LX;

	if (u * d <= 0 && r * l <= 0)
		return true;
	for (int i = 0; i < 4; ++i) {
		int X = std::min(std::abs(r), std::abs(l));
		int Y = std::min(std::abs(u), std::abs(d));

		if (u * d <= 0) {
			if (X <= Ld) return true;
		}
		else if (r * l <= 0) {
			if (Y <= Ld) return true;
		}
		else if (X + Y <= Ld)
			return true;
	}
	return false;
}
int main() {
	for (int j = 0; j < 2; ++j)
		for (int i = 0; i < 4; ++i)
			std::cin >> x[i][j] >> y[i][j];

	std::cout << (check() ? "YES" : "NO");
}
*/

/*
//990D	--1700
#include <iostream>
int n, a, b, m[1007][1007];
int main() {
	std::cin >> n >> a >> b;

	if ((a > 1 && b > 1) || (a == b && n > 1 && n < 4)) {
		std::cout << "NO";
		return 0;
	}
	std::cout << "YES\n";
	if (a == b) {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				std::cout << (i - j == 1 || j - i == 1 ? 1 : 0);
			}
			std::cout << "\n";
		}
	}
	else {
		for (int i = n; i > a && i > b; --i) {
			m[0][i - 1] = 1;
			m[i - 1][0] = 1;
		}
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (i == j)
					std::cout << "0";
				else
					std::cout << (a > b ? m[i][j] : (m[i][j] + 1) % 2);
			}
			std::cout << "\n";
		}
	}
	return 0;
}
*/

/*
//983A	--1700
#include <iostream>
long long n, p, q, b;

long long nod(long long a, long long b) {
	while (a && b)
		if (a >= b) a %= b;
		else b %= a;
	return a | b;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	std::cin >> n;
	for (int in = 0; in < n; ++in) {
		std::cin >> p >> q >> b;
		q /= nod(p, q);
		long long nd;
		while ((nd = nod(q, b)) != 1)
			while (q % nd == 0)
				q /= nd;
		std::cout << (q == 1 ? "Finite" : "Infinite") << "\n";
	}
}
*/

/*
//980С	--1700
#include <iostream>
int n, k, p[100007], ch[256], it;
int main() {
	for (int i = 0; i < 256; ++i)
		ch[i] = -1;

	std::cin >> n >> k;
	for (int i = 0; i < n; ++i) {
		std::cin >> p[i];
	}
	for (int i=0;i<n;++i) {
		int t = p[i];
		if (ch[t] == -1) {
			int it = t;
			while (it > 0 && it - 1 > t - k && ch[it - 1] == -1)
				--it;
			if (it > 0 && t - ch[it - 1] < k)
				it = ch[it - 1];
			for (int j = t;j >= it; --j) {
				ch[j] = it;
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		std::cout << ch[p[i]] << " ";
	}
	return 0;
}
*/

/*
//1118B
#include <iostream>
int n, a[200007], sm[2][200007], ans;
int main() {
	std::cin >> n;
	for (int i = 1; i <= n; ++i) {
		std::cin >> a[i];
		sm[i % 2][i] = sm[i % 2][i - 1] + a[i];
		sm[(i + 1) % 2][i] = sm[(i + 1) % 2][i - 1];
	}
	for (int i = 1; i <= n; ++i) {
		if (sm[0][i - 1] + sm[1][n] - sm[1][i] == sm[1][i - 1] + sm[0][n] - sm[0][i]) {
			++ans;
		}
	}
	std::cout << ans;
	return 0;
}
*/

/*
//1118A
#include <iostream>
long long q, n, a, b, ans;
int main() {
	std::cin >> q;
	for (int i = 0; i < q; ++i) {
		std::cin >> n >> a >> b;
		if (a * 2 <= b) ans = n * a ;
		else ans = n / 2 * b + (n % 2 ? a : 0);
		std::cout << ans << "\n";
	}
}
*/

/*
//1117C
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
string s;
int x, y, UD[100007], LR[100007], n;

bool yes(long long step) {
	long long ud = (long long)UD[n] * (step / n) + UD[step % n];
	long long lr = (long long)LR[n] * (step / n) + LR[step % n];

	return (abs(y - ud) + abs(x - lr) <= step);
}

int main() {
	IOS;
	int x1, y1;
	cin >> x1 >> y1 >> x >> y >> n >> s;
	x -= x1, y -= y1;
	for (int i = 0; i < n; ++i) {
		UD[i + 1] = UD[i];
		LR[i + 1] = LR[i];
		switch (s[i]) {
		case 'U':	++UD[i + 1];	break;
		case 'D':	--UD[i + 1];	break;
		case 'L':	--LR[i + 1];	break;
		case 'R':	++LR[i + 1];	break;
		}
	}
	long long ans = (1LL << 60) - 1;
	if (!yes(ans)) {
		ans = -1;
	}
	else {
		for (int i = 59; i >= 0; --i) {
			if (yes(ans - (1LL << i))) {
				ans -= 1LL << i;
			}
		}
	}
	cout << ans;
	return 0;
}
*/

/*
//1117B
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
long long n, m, k, a[200007], it;
long long ans;
int main() {
	IOS;
	cin >> n >> m >> k;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	sort(a, a + n);
	long long cnt = m / (k + 1);
	ans = cnt * ((long long)a[n - 1] * k + a[n - 2]);
	ans += (long long)a[n - 1] * (m - cnt * (k + 1));

	std::cout << ans;
	return 0;
}
*/

/*
//1117A
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int n, a[100007], mx, l, r, L, R;
int main() {
	IOS;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		if (a[i] > mx)
			mx = a[i];
	}
	a[n] = -1;
	for (int i = 0; i < n; ++i) {
		if (a[i] == mx) {
			l = i;
			r = i;
			while (i < n && a[i + 1] == mx) {
				++i;
				r = i;
			}
			if (r - l >= R - L) {
				R = r;
				L = l;
			}
		}
	}
	cout << R - L + 1;
	return 0;
}
*/

/*
//1109A	--1600
#include <iostream>
int n, a[300007], was[2][1 << 20 + 3], x;
long long ans;
int main() {
	std::cin >> n;
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
	}
	was[1][0] = 1;
	for (int i = 0; i < n; ++i) {
		x ^= a[i];
		ans += was[i % 2][x];
		++was[i % 2][x];
	}
	std::cout << ans;
}
*/

/*
//1111B	--1600
#include <iostream>
#include <algorithm>
int n, m, k, a[100007], l, r, rd;
long long sm;
int main() {
	std::cin >> n >> k >> m;
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
		sm += a[i];
	}
	std::sort(a, a + n);
	l = 0, r = n - 1, rd = 0;
	if (sm / n == a[l] && m > n - 1) {
		l = r;
		sm = a[r];
		m -= n - 1;
	}
	while (m && l <= r) {
		if (n - l - 1 != 0 && (sm - a[l]) * (n - l) > (sm + 1) * (n - l - 1) ) {
			sm -= a[l++];
		}
		else {
			if (rd < k) {
				++rd;
			}
			else {
				--r;
				rd = 0;
			}
			if (l <= r)
				sm++;
		}
		--m;
	}
	std::cout.precision(12);
	std::cout << (double)sm / (n - l);
}
*/

/*
//1110C	--1500
#include <iostream>
#include <set>
int q, a, b;
std::set<int> n2;
int main() {
	q = 1;
	for (int i = 0; i < 25; ++i) {
		q *= 2;
		n2.insert(q - 1);
	}
	std::cin >> q;
	for (int i = 0; i < q; ++i) {
		std::cin >> a;
		b = 1;
		if (n2.count(a)) {
			for (int j = 2; j*j <= a; ++j) {
				if (a % j == 0) {
					b = a / j;
					break;
				}
			}
		}
		else {
			for (auto it = n2.begin(); it != n2.end(); ++it) {
				if (*it >= a) {
					b = *it;
					break;
				}
			}
		}
		std::cout << b << "\n";
	}
}
*/

/*
//1113B	--1300
#include <iostream>
#include <algorithm>
int n, ans, a[50007], ost;
void f() {
	for (int i = n - 1; i > 0 && a[0] < a[i]; --i) {
		for (int j = 2; j*j <= a[i]; ++j) {
			if (a[i] % j == 0) {
				if (a[i] / j + a[0] * j < a[i] + a[0]) {
					int lost = a[i] / j + a[0] * j - (a[i] + a[0]);
					if (lost < ost)
						ost = lost;
				}
			}
		}
	}
}
int main() {
	std::cin >> n;
	for (int i = 0; i < n; ++i)
		std::cin >> a[i];
	std::sort(a, a + n);
	f();
	ans = ost;
	for (int i = 0; i < n; ++i)
		ans += a[i];
	std::cout << ans;
}
*/

/*
//1113A --900
#include <iostream>
int n, v, ans;
int main() {
	std::cin >> n >> v;
	if (n > v - 1) {
		ans = v + (n - v + 2)*(n - v - 1) / 2;
	}
	else {
		ans = n - 1;
	}
	std::cout << ans;
}
*/

/*
//1114B	--1500
#include <iostream>
#include <vector>
#include <algorithm>
typedef std::pair<int, int> myt;
std::vector< myt > v;
int n, m, k, a;
long long sum;
int main() {
	std::cin >> n >> m >> k;
	for (int i = 1; i <= n; ++i) {
		std::cin >> a;
		v.push_back({ a, i });
	}
	std::sort(v.begin(), v.end(), [](myt a, myt b) { return a.first > b.first; });
	std::sort(v.begin(), v.begin() + m * k, [](myt a, myt b) { return a.second < b.second; });
	for (int i = 0; i < m*k; ++i)
		sum += v[i].first;
	std::cout << sum << "\n";
	for (int i = 1; i < k; ++i)
		std::cout << v[i * m - 1].second << " ";
}
*/

/*
//1110B --1400
#include <iostream>
#include <vector>
#include <algorithm>
std::vector<int> ost;
int n, m, k, b, d, ans;
int main() {
	std::cin >> n >> m >> k;
	std::cin >> d;
	for (int i = 1; i < n; ++i) {
		std::cin >> b;
		if (b - d - 1)
			ost.push_back(b - d - 1);
		d = b;
	}
	ans = n;
	std::sort(ost.begin(), ost.end());
	for (int i = ost.size() + 1, j = 0; i > k; --i, ++j) {
		ans += ost[j];
	}
	std::cout << ans;
}
*/

/*
//1111A --1000
#include <iostream>
#include <set>
#include <string>
std::string s, t;
std::set<char> q;
int main() {
	q.insert({ 'a','e','i','o','u' });
	std::cin >> s >> t;
	for (int i = 0; i < s.size(); ++i) {
		if (q.count(s[i])) s[i] = '0';
		else s[i] = '1';
	}
	for (int i = 0; i < t.size(); ++i) {
		if (q.count(t[i])) t[i] = '0';
		else t[i] = '1';
	}
	std::cout << (s == t ? "Yes" : "No");
}
*/

/*
//1110A	--1000
#include <iostream>
int b, k, a, ans;
int main() {
	std::cin >> b >> k;
	if (b % 2 == 1) {
		for (int i = 1; i < k; ++i) {
			std::cin >> a;
			ans += (a % 2 == 1 ? 1 : 0);
		}
	}
	else {
		for (int i = 1; i < k; ++i) {
			std::cin >> a;
		}
	}
	std::cin >> a;
	ans += (a % 2 == 1 ? 1 : 0);
	std::cout << (ans % 2 == 1 ? "odd" : "even");
}
*/

/*
//1114A	--800
#include <iostream>
int x, y, z, a, b, c;
int main() {
	std::cin >> x >> y >> z >> a >> b >> c;
	if (x > a) {
		std::cout << "NO";
	}
	else {
		b += a - x;
		if (y > b) {
			std::cout << "NO";
		}
		else {
			c += b - y;
			if (z > c) {
				std::cout << "NO";
			}
			else {
				std::cout << "YES";
			}
		}
	}
}
*/

/*
//1106D	--1500
#include <iostream>
#include <set>
#include <vector>
int n, m, u, v;
std::vector<int> vm[100007], ans;
std::set<int> was, que;
void add() {
	if (!que.size()) return;

	int i = *que.begin();
	ans.push_back(i + 1);
	was.insert(i);
	que.erase(que.begin());
	for (auto el : vm[i]) {
		if (!was.count(el))
			que.insert(el);
	}
}
int main() {
	std::cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		std::cin >> u >> v; --v; --u;
		vm[u].push_back(v);
		vm[v].push_back(u);
	}
	que.insert(0);
	while (que.size()) {
		add();
	}
	for (auto el : ans)
		std::cout << el << " ";
}
*/

/*
//1106C	--1000
#include <iostream>
#include <algorithm>
int n, a[300007];
long long ans;
int main() {
	std::cin >> n;
	for (int i = 0; i < n; ++i)
		std::cin >> a[i];
	std::sort(a, a + n);
	for (int i = 0; i < n / 2; ++i)
		ans += (a[i] + a[n - 1 - i]) * (a[i] + a[n - 1 - i]);
	std::cout << ans;
}
*/

/*
//1106B	--1500
#include <iostream>
#include <algorithm>
int n, m, a[100007], c[100007], ci, t, d;
std::pair<int, int> cI[100007];
int main() {
	std::cin >> n >> m;
	for (int i = 0; i < n; ++i)
		std::cin >> a[i];
	for (int i = 0; i < n; ++i) {
		std::cin >> c[i];
		cI[i] = std::make_pair(c[i], i);
	}
	std::sort(cI, cI + n);

	for (int i = 0; i < m; ++i) {
		long long ans = 0;
		std::cin >> t >> d;
		--t;
		if (a[t] >= d) {
			ans = (long long)c[t] * d;
			a[t] -= d;
		}
		else {
			ans = (long long)c[t] * a[t];
			d -= a[t];
			a[t] = 0;
			while (d > 0 && ci < n) {
				int it = cI[ci].second;
				if (a[it] >= d) {
					ans += (long long)c[it] * d;
					a[it] -= d;
					d = 0;
				}
				else {
					ans += (long long)c[it] * a[it];
					d -= a[it];
					a[it] = 0;
					++ci;
				}
			}
			if (d) ans = 0;
		}
		std::cout << ans << "\n";
	}
}
*/

/*
//1106A	--800
#include <iostream>
#include <string>
std::string s[507];
int n, k;
int main() {
	std::cin >> n;
	for (int i = 0; i < n; ++i)
		std::cin >> s[i];
	for (int i = 1; i < n - 1; ++i) {
		for (int j = 1; j < n - 1; ++j) {
			if (s[i][j] == 'X' && s[i - 1][j - 1] == 'X' && s[i - 1][j + 1] == 'X' && s[i + 1][j - 1] == 'X' && s[i + 1][j + 1] == 'X') {
				++k;
			}
		}
	}
	std::cout << k;
}
*/

/*
//977F	--1700
#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
std::map<int, int> m;
std::vector<int> res;
int n, a[20007], dp[20007], ans, lst;
int main() {
	std::cin >> n;
	for (int i = 0; i < n; ++i)
		std::cin >> a[i];
	for (int i = 0; i < n; ++i) {
		int x = a[i];
		dp[x] = dp[x - 1] + 1;
		if (ans < dp[x]) {
			ans = dp[x];
			lst = x;
		}
	}
	for (int i = n - 1; i >= 0; --i) {
		if (a[i] == lst) {
			res.push_back(i + 1);
			--lst;
		}
	}
	std::cout << ans << "\n";
	for (int i = res.size() - 1; i >= 0; --i)
		std::cout << res[i] << " ";
}
*/

/*
//960C	--1700
#include <iostream>
#include <vector>
int x, d, n;
long long val = 1;
std::vector<int> v;
std::vector<long long> ans;
int main() {
	std::cin >> x >> d;
	for (int i = 1, nd = 1; nd < 1000000000; ++i) {
		v.push_back(nd - 1);
		nd *= 2;
	}
	for (int i = v.size() - 1; i > 0; --i) {
		while (x >= v[i]) {
			for (int j = 0; j < i; ++j)
				ans.push_back(val);
			val += d;
			x -= v[i];
		}
	}
	std::cout << ans.size() << "\n";
	for (auto el : ans)
		std::cout << el << " ";
}
*/

/*
//954C	--1700
#include <iostream>
#include <algorithm>
int n, a[200007], x, y, xma, xmi, yma, ymi, i, j, q;
int f1(int a, int b) {
	return (a / b + (a%b == 0 ? 0 : 1));
}
int main() {
	std::cin >> n;
	for (int i = 0; i < n; ++i)
		std::cin >> a[i];
	for (int in = 1; in < n; ++in) {
		if (a[in] - a[in - 1] == 1) {
			++i; xma = std::max(xma, i);
		}
		else if (a[in] - a[in - 1] == -1) {
			--i; xmi = std::min(xmi, i);
		}
		else if (q == 0) {
			q = std::abs(a[in] - a[in - 1]);
			if (q == 0) {
				std::cout << "NO";
				return 0;
			}
			if (a[in] - a[in - 1] > 0) {
				++j; yma = j;
			}
			else {
				--j; ymi = -j;
			}
		}
		else if (q == a[in]- a[in - 1]) {
			++j; yma = std::max(yma, j);
		}
		else if (q == a[in - 1] - a[in]) {
			--j; ymi = std::min(ymi, j);
		}
		else {
			std::cout << "NO";
			return 0;
		}
	}
	if (q == 0) {
		std::cout << "YES\n" << *std::max_element(a, a + n) << " 1";
		return 0;
	}
	x = q;
	y = f1(a[0], x) + yma;
	if (xma - xmi + 1 > x || x > 1000000000 || y < 1 || y > 1000000000) {
		std::cout << "NO";
		return 0;
	}
	if ((a[0] % x ? a[0] % x : x) + xmi <= 0 ||
		(a[0] % x ? a[0] % x : x) + xma > x) {
		std::cout << "NO";
		return 0;
	}
	std::cout << "YES\n" << y << " " << x;
}
*/

/*
//1107C	--1300
#include <iostream>
#include <string>
#include <algorithm>
int n, k, a[200007], cnt;
std::string s;
long long dmg;
char old = '0';
void make(int x, int y) {
	std::sort(a + x, a + y);
	for (int i = x; i < y - k; ++i)
		dmg -= a[i];
}
int main() {
	std::cin >> n >> k;
	for (int i = 0; i < n; ++i)
		std::cin >> a[i], dmg += a[i];
	std::cin >> s;
	s = s + '1';
	for (int i = 0; i < n; ++i) {
		if (s[i] == old) ++cnt;
		else {
			if (cnt >= k)
				make(i - cnt, i);
			cnt = 1;
			old = s[i];
		}
	}
	if (cnt >= k)
		make(n - cnt, n);
	std::cout << dmg;
}
*/

/*
//1107B	--1100
#include <iostream>
#include <vector>
std::vector<long long> v[10];
int n, x;
long long k;
int main() {
	std::cin >> n;
	for (int in = 0; in < n; ++in) {
		std::cin >> k >> x;
		std::cout << 9 * (k - 1) + x << "\n";
	}
}
*/

/*
//1107A	--1000
#include <iostream>
#include <string>
int q, n;
std::string s;
int main() {
	std::cin >> q;
	for (int qi = 0; qi < q; ++qi) {
		std::cin >> n >> s;
		if (s.size() == 2 && s[0] >= s[1]) {
			std::cout << "NO\n";
			continue;
		}
		std::cout << "YES\n2\n" << s[0] << " " << s.substr(1) << "\n";
	}
}
*/

/*
//938C	--1700
#include <iostream>
#include <math.h>
long long t, x, n, m, M;
int main() {
	std::cin >> t;
	for (int i = 0; i < t; ++i) {
		std::cin >> x;
		for (n = sqrt(x) + 1; true; ++n) {
			M = n * n - x;
			m = sqrt(M);
			if (m * m == M && n % m < n / m)
				break;
			if (m > n / 2)
				break;
		}
		if (m > n / 2 && n > 1) {
			std::cout << "-1\n";
			continue;
		}

		m = n / m;
		std::cout << n << " " << m << "\n";
	}
}
*/

/*
//931C	--1700
#include <iostream>
#include <algorithm>
int n, x[100007], base, p[3], ans, mx;
int main() {
	std::cin >> n;
	for (int i = 0; i < n; ++i)
		std::cin >> x[i];
	base = *std::min_element(x, x + n);
	mx = *std::max_element(x, x + n);
	ans = n;
	for (int i = 0; i < n; ++i)
		x[i] -= base, p[x[i]]++;
	if (mx - base == 2) {
		if (p[1] % 2 + p[0] + p[2] > p[1] + std::abs(p[0] - p[2])) {
			ans = p[1] + std::abs(p[0] - p[2]);
			int t = std::min(p[0], p[2]);
			p[0] -= t;
			p[1] += t * 2;
			p[2] -= t;
		}
		else {
			int t = p[1] / 2;
			ans = p[1] % 2 + p[0] + p[2];
			p[0] += t;
			p[1] %= 2;
			p[2] += t;
		}
	}
	std::cout << ans << "\n";
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < p[i]; ++j) {
			std::cout << base + i << " ";
		}
	}
}
*/

/*
//1108D	--1400
#include <iostream>
#include <string>
int n, ans;
std::string s, t = "RGB";
int main() {
	std::cin >> n >> s;
	for (int i = 1; i < n - 1; ++i) {
		if (s[i] == s[i - 1] && s[i] == s[i + 1]) {
			for (int j = 0; j < 3; ++j) {
				if (t[j] != s[i - 1]) {
					s[i] = t[j];
					++ans;
					break;
				}
			}
		}
	}
	for (int i = 1; i < n - 1; ++i) {
		if (s[i] == s[i - 1] || s[i] == s[i + 1]) {
			for (int j = 0; j < 3; ++j) {
				if (t[j] != s[i - 1] && t[j] != s[i + 1]) {
					s[i] = t[j];
					++ans;
					break;
				}
			}
		}
	}
	if (s.size() == 2 && s[0] == s[1]) {
		for (int j = 0; j < 3; ++j) {
			if (t[j] != s[0]) {
				s[1] = t[j];
				++ans;
				break;
			}
		}
	}
	std::cout << ans << "\n" << s;
}
*/

/*
//1108C	--1300
#include <iostream>
#include <string>
#include <algorithm>
int n;
std::string s;
std::string p[] = { "RGB", "RBG", "GRB", "GBR", "BGR", "BRG" };
int a[6];
int chk(std::string q) {
	int rez = 0;
	for (int i = 0; i < n; ++i) {
		if (s[i] != q[i % 3])
			++rez;
	}
	return rez;
}
void print(int it) {
	for (int i = 0; i < n; ++i) {
		std::cout << p[it][i % 3];
	}
}
int main() {
	std::cin >> n >> s;
	for (int i = 0; i < 6; ++i)
		a[i] = chk(p[i]);
	auto mn = std::min_element(a, a + 6);
	std::cout << *mn << "\n";
	print(mn - a);

}
*/

/*
//1108B	--1100
#include <iostream>
#include <algorithm>
int n, d[10007], x, y, was[10007];
int main() {
	std::cin >> n;
	for (int i = 0; i < n; ++i)
		std::cin >> d[i];
	int x = *std::max_element(d, d + n);
	int it = 0, X = x;
	while (X > 1 && it < n) {
		if (was[d[it]] == 0 && X % d[it] == 0) {
			was[d[it]] = 1;
			d[it] = 1;
		}
		++it;
	}
	y = *std::max_element(d, d + n);
	std::cout << x << " " << y;
}
*/

/*
//1108A	--800
#include <iostream>
int q, l1, r1, l2, r2;
int main() {
	std::cin >> q;
	for (int i = 0; i < q; ++i) {
		std::cin >> l1 >> r1 >> l2 >> r2;
		if (l1 <= l2)
			std::cout << l1 << " " << r2 << "\n";
		else
			std::cout << r1 << " " << l2 << "\n";
	}
}
*/

/*
//883A	--2300
#include <iostream>
#include <algorithm>
long long n, m, a, d, t[100007], old, ans, aind, firstA, stepD;
int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);
	std::cin >> n >> m >> a >> d;
	for (int i = 0; i < m; ++i)
		std::cin >> t[i];

	aind = d / a * a + a;
	for (int i = 0; i < m; ++i) {
		if (t[i] <= old) continue;

		if (t[i] <= n * a) {
			firstA = (old / a + 1) * a;
			if (t[i] <= firstA) {
				++ans;
				old = t[i] + d;
			}
			else {
				stepD = (t[i] - firstA) / aind + ((t[i] - firstA) % aind ? 1 : 0);
				ans += stepD;
				old = firstA + stepD * aind - (a - d % a);
				if (old < t[i]) {
					++ans;
					firstA = (old / a + 1) * a;
					old = std::min(t[i], firstA) + d;
				}
			}
		}
		else {
			if (old < n * a) {
				firstA = (old / a + 1) * a;
				stepD = (n * a - firstA) / aind + ((n * a - firstA) % aind ? 1 : 0);
				ans += stepD;
				old = firstA + stepD * aind - (a - d % a);
				if (old < n * a) {
					++ans;
					firstA = (old / a + 1) * a;
					old = firstA + d;
				}
			}
			if (old < t[i]) {
				++ans;
				old = t[i] + d;
			}
		}
	}
	if (old < a * n) {
		firstA = (old / a + 1) * a;
		stepD = (a * n - firstA) / aind + ((a * n - firstA) % aind ? 1 : 0);
		ans += stepD;
		old = firstA + stepD * aind - (a - d % a);
		if (old < a * n) {
			++ans;
		}
	}
	std::cout << ans;
}
*/

/*
//999D	--1900
#include <iostream>
#include <vector>
#include <algorithm>
std::vector<int> v[200007];
int n, m, a[200007], c[200007], nm;
long long cnt;
int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);
	std::cin >> n >> m;
	nm = n / m;
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
		++c[a[i] % m];
	}
	for (int i = 0; i < n; ++i) {
		if (c[a[i] % m] > nm)
			v[a[i] % m].push_back(i);
	}
	for (int i = 0, j = 0; i < m; ++i) {
		while (c[i] > nm) {
			j = std::max(i, j);
			while (c[j % m] >= nm) ++j;
			int sz = std::min(nm - c[j % m], c[i] - nm), dlt = j - i;;
			c[j % m] += sz, c[i] -= sz, cnt += (long long)sz * dlt;
			while (sz--) {
				a[v[i].back()] += dlt;
				v[i].pop_back();
			}
		}
	}
	std::cout << cnt << "\n";
	for (int i = 0; i < n; ++i)
		std::cout << a[i] << " ";
}
*/

/*
//988E	--2100
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
std::string s;
std::vector<int> v[10];
const int inf = 1000000000;
int ans = inf;
int f(int x, int y) {
	int rez = x + y - (x > y || s[x] == s[y] ? 1 : 0);
	if (std::max(x, y) == s.size() - 1 && s.size() > 2) {
		int it = 2, dec = 0;
		while (s.size() - it > 0 && (
					s[s.size() - it] == '0' ||
					s.size() - it == std::min(x, y)
				)
			) {
			if (s.size() - it == std::min(x, y))
				++dec;
			++it;
		}
		if (s[s.size() - it] == '0' || s.size() - it == std::min(x, y)) { return inf; }
		return rez + it - dec - 2;
	}
	return rez;
}
int main() {
	std::cin >> s;
	std::reverse(s.begin(), s.end());
	for (int i = 0; i < s.size(); ++i) {
		v[s[i] - '0'].push_back(i);
	}
	if (v[0].size() > 1) {
		ans = std::min(ans, f(v[0][0], v[0][1]));
	}
	if (v[2].size() && v[5].size()) {
		ans = std::min(ans, f(v[2][0], v[5][0]));
	}
	if (v[5].size() && v[0].size()) {
		ans = std::min(ans, f(v[5][0], v[0][0]));
	}
	if (v[7].size() && v[5].size()) {
		ans = std::min(ans, f(v[7][0], v[5][0]));
	}
	std::cout << (ans == inf ? -1 : ans);
}
*/

/*
//174C	--1800
#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
int n, a[100007];
std::vector<std::pair<int, int>> ans;
std::stack<int> s;
int main() {
	std::cin >> n;
	for (int i = 1; i <= n; ++i)
		std::cin >> a[i];
	s.push(0);
	for (int i = 1; i <= n + 1; ++i) {
		while (a[i] < a[s.top()]) {
			int el = s.top();
			s.pop();
			for (int j = 0; j < a[el] - std::max(a[i], a[s.top()]); ++j) {
				ans.push_back({ el, i - 1 });
			}
			if (a[i] > a[s.top()]) {
				a[el] = a[i];
				s.push(el);
			}
		}
		if (a[i] > a[s.top()]) {
			s.push(i);
		}
	}
	std::cout << ans.size() << "\n";
	for (auto el : ans)
		std::cout << el.first << " " << el.second << "\n";
}
*/

/*
//REWRITE IN PYTHON
//926G	--1700
#include <iostream>
#include <algorithm>
int n, a, odd[2], ans;
int main() {
	std::cin >> n;
	for (int i = 0; i < n; ++i) {
		std::cin >> a;
		odd[a % 2]++;
	}
	ans = std::min(odd[0], odd[1]);
	ans += (odd[1] - ans) / 3;
	std::cout << ans;
}
*/

/*
//1104D
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
using namespace std;
const int inf = 1000000000;
int step = 2;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
string status;
bool ask(int x, int y) {
	cout << "? " << x << " " << y << "\n";
	fflush(stdout);
	string rez;
	cin >> rez;
	if (rez == "e") exit(0);
	return rez == "x";
}
int make() {
	if (ask(0, 1)) return 1;
	int l = 1, r;
	while (ask(l * 2, l)) l *= 2;
	r = min(l * 2 + 1, inf); ++l;
	while (r > l) {
		int mid = (l + r) / 2;
		if (ask(mid, (mid + 1) / 2)) l = mid + 1;
		else r = mid;
	}
	return l;
}
int main() {
	//IOS;
	while (true) {
		cin >> status;
		if (status == "start") {
			std::cout << "! " << make() << "\n";
			fflush(stdout);
		}
		else break;
	}
	return 0;
}
*/

/*
//1104C
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
string s;
int a1, a4;
int main() {
	IOS;
	cin >> s;
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] == '0') {
			cout << a1 * 2 + 1 << " 1\n";
			a1 = 1 - a1;
		}
		else {
			cout << a4 + 1 << " 3\n";
			a4 = (a4 + 1) % 4;
		}
	}
	return 0;
}
*/

/*
//1104B
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <stack>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
string s;
stack<int> q;
int steps;
int main() {
	IOS;
	cin >> s;
	for (int i = 0; i < s.size(); ++i) {
		if (q.empty() || q.top() != s[i]) {
			q.push(s[i]);
			continue;
		}
		++steps;
		q.pop();
	}
	cout << (steps % 2 ? "Yes" : "No");
	return 0;
}
*/


/*
//1004A
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int n;
int main() {
	IOS;
	std::cin >> n;
	cout << n << "\n";
	for (int i = 0; i < n; ++i)
		cout << "1 ";
	return 0;
}
*/

/*
//925A	--1700
#include <iostream>
#include <algorithm>
const int inf = 1000000000;
int n, m, cl, ce, v, q, x[2], y[2], l[100007], e[100007];
int f(int a, int b) {
	return (a + b - 1) / b;
}
int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);
	std::cin >> n >> m >> cl >> ce >> v;
	for (int i = 0; i < cl; ++i)
		std::cin >> q,
		l[i] = q;
	for (int i = 0; i < ce; ++i)
		std::cin >> q,
		e[i] = q;
	std::cin >> q;
	for (int i = 0; i < q; ++i) {
		int ans = inf;
		std::cin >> y[0] >> x[0] >> y[1] >> x[1];
		if (y[0] == y[1]) {
			std::cout << std::abs(x[0] - x[1]) << "\n";
			continue;
		}
		int it = std::lower_bound(l, l + cl, x[0]) - l;
		if (it < cl)
			ans = std::abs(x[0] - l[it]) + std::abs(y[0] - y[1]) + std::abs(x[1] - l[it]);

		if (it != 0)
			ans = std::min(ans, std::abs(x[0] - l[it - 1]) + std::abs(y[0] - y[1]) + std::abs(x[1] - l[it - 1]));

		it = std::lower_bound(e, e + ce, x[0]) - e;
		if (it < ce)
			ans = std::min(ans, std::abs(x[0] - e[it]) + f(std::abs(y[0] - y[1]), v) + std::abs(x[1] - e[it]));

		if (it != 0)
			ans = std::min(ans, std::abs(x[0] - e[it - 1]) + f(std::abs(y[0] - y[1]), v) + std::abs(x[1] - e[it - 1]));

		std::cout << ans << "\n";
	}
}
*/

/*
//911D	--1700
#include <iostream>
int n, a[1507], m, l, r, swap, ans;
int main() {
	std::cin >> n;
	for (int i = 1; i <= n; ++i)
		std::cin >> a[i];

	for (int i = 1; i <= n; ++i)
		for (int j = i + 1; j <= n; ++j)
			if (a[i] > a[j])
				++swap;
	ans = swap % 2;

	std::cin >> m;
	for (int i = 0; i < m; ++i) {
		std::cin >> l >> r;
		int s = r - l + 1;
		int cnt = s * (s - 1) / 2;
		ans ^= cnt & 1;
		std::cout << (ans % 2 ? "odd" : "even") << "\n";
	}
}
*/

/*
//910C	--1700
#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <map>
std::string s[1007];
int n, ans, alf[10], d[6];
std::pair<int, char> a[10];
std::set<char> first;
std::map<char, int> val;
int main() {
	d[0] = 1;
	for (int i = 1; i < 6; ++i) {
		d[i] = d[i - 1] * 10;
	}
	std::cin >> n;
	for (int i = 0; i < n; ++i) {
		std::cin >> s[i];
		first.insert(s[i][0]);
		for (int j = 0, sz = s[i].size(); j < s[i].size(); ++j) {
			alf[s[i][j] - 'a'] += d[--sz];
		}
	}
	for (int i = 0; i < 10; ++i) {
		a[i] = std::make_pair(alf[i], 'a' + i);
	}
	std::sort(a, a + 10);
	for (int i = 0, j = 9; i < 10; ++i, --j) {
		if (!i) {
			while (first.count(a[j].second)) --j;
			val[a[j].second] = i;
			j = 10;
			continue;
		}
		if (val.count(a[j].second)) --j;
		val[a[j].second] = i;
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0, sz = s[i].size(); j < s[i].size(); ++j) {
			ans += val[s[i][j]] * d[--sz];
		}
	}
	std::cout << ans;
}
*/

/*
//900C	--1700
#include <iostream>
const int inf = 1000000007;
int n, x, max1 = -inf, max2 = -inf, a[100007], ans = 1;
int main() {
	std::cin >> n;
	for (int i = 1; i <= n; ++i) {
		std::cin >> x;
		if (x > max1) max2 = max1, max1 = x, a[x] = -1;
		else if (x > max2) max2 = x, ++a[max1];
	}
	for (int i = 2; i <= n; ++i) {
		if (a[i] > a[ans])
			ans = i;
	}
	std::cout << ans;
}
*/

/*
//1042C	--1700
#include <iostream>
#include <vector>
#include <algorithm>
int n, a[200007], cnt;
std::vector<std::pair<int,int>> v[3];
void print(char id, int f, int s = 0) {
	if (cnt >= n - 1)
		return;
	if (id == 2) {
		std::cout << "1 " << f + 1 << " " << s + 1 << "\n";
	}
	else {
		std::cout << "2 " << f + 1 << "\n";
	}
	++cnt;
}
int main() {
	std::cin >> n;
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
		if (a[i] == 0)
			v[0].push_back(std::make_pair(a[i], i));
		else if (a[i] > 0)
			v[2].push_back(std::make_pair(a[i], i));
		else
			v[1].push_back(std::make_pair(a[i], i));
	}
	std::sort(v[1].begin(), v[1].end());

	if (v[0].size()) {
		for (int i = v[0].size() - 1; i > 0; --i) {
			print(2, v[0][i].second, v[0][i - 1].second);
		}
	}
	int it = 0;
	if (v[0].size()) {
		if (v[1].size() % 2) {
			print(2, v[1][v[1].size() - 1].second, v[0][0].second);
			it = 1;
		}
		print(1, v[0][0].second);
	}
	else {
		if (v[1].size() % 2) {
			print(1, v[1][v[1].size() - 1].second);
			it = 1;
		}
	}
	for (int i = 0; i < v[1].size() - it; ++i) {
		v[2].push_back(v[1][i]);
	}
	for (int i = 1; i < v[2].size(); ++i) {
		print(2, v[2][i - 1].second, v[2][i].second);
	}
}
*/

/*
//923A	--1700
#include <iostream>
#include <algorithm>
int x2, ans = 1000000000, d[1000007];
int main() {
	std::cin >> x2;
	for (int i = 2; i <= x2; ++i) {
		if (d[i] == 0) {
			for (int j = 2 * i; j <= x2; j += i) {
				d[j] = i;
			}
		}
	}
	for (int i = x2 - d[x2] + 1; i <= x2; ++i) {
		if (d[i]) {
			ans = std::min(ans, i - d[i] + 1);
		}
	}
	std::cout << ans;
}
*/

/*
//1105C	--1500
#include <iostream>
const int inf = 1000000007;
int n, l, r, dp[200007][3];
long long a[3];
int main() {
	std::cin >> n >> l >> r;
	a[0] = a[1] = a[2] = (r - l + 1) / 3;
	for (int i = l; i < l + (r - l + 1) % 3; ++i) {
		++a[i % 3];
	}
	for (int i = 0; i < 3; ++i) {
		dp[1][i] = a[i];
	}
	for (int i = 2; i <= n; ++i) {
		dp[i][0] = (a[0] * dp[i - 1][0]
			+ a[1] * dp[i - 1][2]
			+ a[2] * dp[i - 1][1]
			) % inf;
		dp[i][1] = (a[0] * dp[i - 1][1]
			+ a[1] * dp[i - 1][0]
			+ a[2] * dp[i - 1][2]
			) % inf;
		dp[i][2] = (a[0] * dp[i - 1][2]
			+ a[1] * dp[i - 1][1]
			+ a[2] * dp[i - 1][0]
			) % inf;
	}
	std::cout << dp[n][0];
}
*/

/*
//1105B	--1200
#include <iostream>
#include <string>
int n, k, alf[26], l, ans;
std::string s;
int main() {
	std::cin >> n >> k >> s;
	s = "#" + s;
	for (int i = 1; i <= n; ++i) {
		if (s[i] == s[i - 1])
			++l;
		else
			l = 1;
		if (l == k) {
			alf[s[i] - 'a']++;
			l = 0;
		}
	}
	for (int i = 0; i < 26; ++i) {
		if (alf[i] > ans) {
			ans = alf[i];
		}
	}
	std::cout << ans;
}
*/

/*
//1105A	--1100
#include <iostream>
#include <algorithm>
int n, a[1007], b[107], mn = 1000000000, t, local;
int main() {
	std::cin >> n;
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
	}
	for (int i = 1; i <= 100; ++i) {
		local = 0;
		for (int j = 0; j < n; ++j) {
			int T = std::abs(a[j] - i);
			if (T > 0) --T;
			local += T;
		}
		if (local < mn) {
			t = i;
			mn = local;
		}
	}
	std::cout << t << " " << mn;
}
*/

/*
//919D	--1700
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
int n, m, x, y, ans[300007][26], cnt, ANS = -1;
std::string s;
std::vector<int> v[300007], w(300007);
int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);
	std::cin >> n >> m >> s;
	for (int i = 0; i < m; ++i) {
		std::cin >> x >> y;
		v[--y].push_back(--x);
		w[x]++;
	}
	std::queue<int> q;
	for (int i = 0; i < n; ++i) {
		if (w[i] == 0) {
			q.push(i);
			ans[i][s[i] - 'a'] = 1;
		}
	}
	cnt = n;
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		--cnt;
		for (int i = 0; i < v[now].size(); ++i) {
			for (int alf = 0; alf < 26; ++alf) {
				ans[v[now][i]][alf] = std::max(ans[v[now][i]][alf], ans[now][alf] + (s[v[now][i]] - 'a' == alf));
			}
			w[v[now][i]]--;
			if (!w[v[now][i]])
				q.push(v[now][i]);
		}
	}
	if (cnt) {
		std::cout << -1;
		return 0;
	}
	for (int i = 0; i < n; ++i) {
		for (int alf = 0; alf < 26; ++alf) {
			ANS = std::max(ANS, ans[i][alf]);
		}
	}
	std::cout << ANS;
}
*/

/*
//852G	--1700
#include <iostream>
#include <string>
#include <map>
#include <set>
int N, M, ans;
std::string s;
std::map<std::string, int> m;
std::set<std::string> v;
void make(int it) {
	if (it == s.size()) {
		v.insert(s);
		return;
	}
	if (s[it] != '?') {
		return make(it + 1);
	}
	for (char chg = 'a'; chg <= 'e'; ++chg) {
		s[it] = chg;
		make(it + 1);
	}
	s.erase(s.begin() + it);
	make(it);
	s.insert(s.begin() + it, '?');
}
int main() {
	std::cin >> N >> M;
	for (int i = 0; i < N; ++i) {
		std::cin >> s;
		++m[s];
	}
	for (int i = 0; i < M; ++i) {
		std::cin >> s;
		v.clear();
		make(0);
		ans = 0;
		for (auto el : v) {
			ans += m[el];
		}
		std::cout << ans << "\n";
	}
}
*/

/*
//I Cant
//852G
#include <iostream>
#include <string>
#include <set>
union tree {
	tree(const char q) :q(q) { val = 0; }
	~tree() {};
	char q;
	mutable int val;
	std::set<tree> next;
	bool operator<(const tree & oth) {
		return q < oth.q;
	}
};
int N, M, ans;
std::string s[100007], text;
std::set<tree> tr;
const std::set<tree> *it;
int make(int it) {
	//if (i == text.size() - 1) {
	return 1;
	//}
}
int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);
	std::cin >> N >> M;
	for (int i = 0; i < N; ++i) {
		std::cin >> s[i];
		it = &tr;
		for (int j = 0; j < s[i].size(); ++j) {
			tree el(s[i][j]);
			it->insert(el);
			it = &(it->find(s[i][j]))->next;
		}
		it->find(s[i][s[i].size() - 1])->val += 1;
	}
	it = &tr;
	for (int i = 0; i < M; ++i) {
		std::cin >> text;
		ans = make(i);
		std::cout << ans << "\n";
	}
}
*/

/*
//850A	--1700
#include <iostream>
#include <vector>
#include <math.h>
#define f(a) (a[j]-a[i])*(a[k]-a[i])
#define fy(a) (a[j]-a[i])*(a[j]-a[i])
#define fz(a) (a[k]-a[i])*(a[k]-a[i])
#define PI 3.14159265
int n, a[1007], b[1007], c[1007], d[1007], e[1007];
std::vector<int> ans;
int main() {
	std::cin >> n;
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i] >> b[i] >> c[i] >> d[i] >> e[i];
	}
	for (int i = 0; i < n; ++i) {
		bool ok = true;
		for (int j = 0; j < n; ++j) {
			if (j == i) continue;
			for (int k = 0; k < n; ++k) {
				if (k == i || k == j) continue;
				double x = f(a) + f(b) + f(c) + f(d) + f(e);
				double y = sqrt((double)fy(a) + fy(b) + fy(c) + fy(d) + fy(e));
				double z = sqrt((double)fz(a) + fz(b) + fz(c) + fz(d) + fz(e));
				double alf = acos(x / y / z) * 180.0 / PI;
				if (alf < 90) {
					ok = false;
					break;
				}
			}
			if (!ok) break;
		}
		if (ok) {
			ans.push_back(i + 1);
		}
	}
	std::cout << ans.size() << "\n";
	for (auto el : ans) {
		std::cout << el << " ";
	}
}
*/

/*
//766C	--1700
#include <iostream>
#include <string>
#include <algorithm>
const int inf = 1000000007;
int n, a[26], dp[1007], dp2[1007], l;
std::string s;
int main() {
	std::cin >> n >> s;
	for (int i = 0; i < 26; ++i) {
		std::cin >> a[i];
	}
	dp[0] = 1;
	dp2[0] = 0;
	for (int i = 1; i <= n; ++i) {
		int f = 0;
		dp2[i] = n;
		for (int j = i - 1; j >= 0; --j) {
			f = std::max(f, i - a[s[j] - 'a']);
			if (f > j)
				continue;
			dp[i] = (dp[i] + dp[j]) % inf;
			dp2[i] = std::min(dp2[i], 1 + dp2[j]);
			l = std::max(l, i - j);
		}
	}
	std::cout << dp[n] << "\n" << l << "\n" << dp2[n];
}
*/

/*
//1101C	--1600
#include <iostream>
#include <vector>
#include <algorithm>
int T, n, l, r, a[100007];
int main() {
	std::cin >> T;
	for (int i = 0; i < T; ++i) {
		std::cin >> n;
		std::vector<std::pair<int, std::pair<int, int>>> v(n * 2);
		for (int j = 0; j < n; ++j) {
			a[j] = 2;
			std::cin >> l >> r;
			v[j * 2] = std::make_pair(l, std::make_pair(-1, j));
			v[j * 2 + 1] = std::make_pair(r, std::make_pair(1, j));
		}
		std::sort(v.begin(), v.end());
		int it = 0, cnt = 0;
		bool ok = false;
		while (it < n * 2 - 1) {
			cnt += v[it].second.first;
			a[v[it].second.second] = 1;
			if (cnt == 0 && v[it + 1].first > v[it].first) {
				ok = true;
				break;
			}
			++it;
		}
		if (ok) {
			for (int j = 0; j < n; ++j) {
				std::cout << a[j] << " ";
			}
			std::cout << "\n";
		}
		else {
			std::cout << "-1\n";
		}
	}
}
*/

/*
//1101B	--1300
#include <iostream>
#include <string>
std::string s;
int l, r, ans;
int main() {
	std::cin >> s;
	l = 0;
	while (l < s.size() - 1 && s[l] != '[') {
		++l;
	}
	while (l < s.size() - 1 && s[l] != ':') {
		++l;
	}
	r = s.size() - 1;
	while (r > l && s[r] != ']') {
		--r;
	}
	while (r > l && s[r] != ':') {
		--r;
	}
	if (l != r) {
		for (int i = l; i < r; ++i) {
			if (s[i] == '|') {
				++ans;
			}
		}
		std::cout << ans + 4;
		return 0;
	}
	std::cout << -1;
}
*/

/*
//1101A	--1100
#include <iostream>
int l, r, d, q;
int main() {
	std::cin >> q;
	for (int i = 0; i < q; ++i) {
		std::cin >> l >> r >> d;
		if (l > d) {
			std::cout << d << "\n";
		}
		else {
			std::cout << (long long)(r / d + 1)*d << "\n";
		}
	}
}
*/

/*
//1098A	--1600
#include <iostream>
#include <vector>
std::vector<int> v[100007], s(100007);
int n, p;
const int inf = 1000000007;
long long ans;
void make(int it, int old) {
	if (s[it] < old) {
		std::cout << -1;
		exit(0);
	}
	ans += s[it] - old;
	for (auto el : v[it]) {
		if (v[el].size()) {
			int mn = inf;
			for (auto el2 : v[el]) {
				if (s[el2] < mn)
					mn = s[el2];
			}
			if (mn < s[it]) {
				std::cout << -1;
				exit(0);
			}
			ans += mn - s[it];
			for (auto el2 : v[el]) {
				make(el2, mn);
			}
		}
	}
}
int main() {
	std::cin >> n;
	for (int i = 2; i <= n; ++i) {
		std::cin >> p;
		v[p].push_back(i);
	}
	for (int i = 1; i <= n; ++i) {
		std::cin >> s[i];
	}
	make(1, 0);
	std::cout << ans;
}
*/

/*
//1097C	--1400
#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <stack>
int n, v[100007], ans;
bool normal;
std::string s;
std::map<int, std::pair<int, int>> a;
int main() {
	std::cin >> n;
	for (int i = 0; i < n; ++i) {
		std::cin >> s;
		std::stack<char> st;
		for (int j = 0; j < s.size(); ++j) {
			if (s[j] == ')' && !st.empty() && st.top() == '(') {
				st.pop();
			}
			else {
				st.push(s[j]);
			}
		}
		char etalon;
		if (!st.empty())
			etalon = st.top();
		while (!st.empty() && etalon == st.top()) {
			v[i] += (st.top() == ')' ? -1 : 1);
			st.pop();
		}

		if (st.empty()) {
			if (v[i] >= 0) {
				++a[v[i]].first;
			}
			if (v[i] <= 0) {
				++a[-v[i]].second;
			}
		}
	}
	a[0].first /= 2;
	a[0].second /= 2;
	for (auto el : a) {
		ans += std::min(el.second.first, el.second.second);
	}
	std::cout << ans;
}
*/

/*
//1097B	--1200
#include <iostream>
int n, m, a[100];
int main() {
	std::cin >> n;
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
	}
	m = 1;
	for (int i = 0; i < n; ++i) {
		m *= 2;
	}
	for (int i = 0; i < m; ++i) {
		int val = 0, el = i;
		for (int j = 0; j < n; ++j) {
			val += (el % 2 ? 1 : -1) * a[j];
			el /= 2;
		}
		if (val % 360 == 0) {
			std::cout << "YES";
			return 0;
		}
	}
	std::cout << "NO";
}
*/

/*
//1095D	--1600
#include <iostream>
#include <vector>
int n, a, b, en, A, B;
bool frst = true;
std::vector<std::pair<int, int> > v(200007);
std::vector<int> ans;
void make(int it) {
	ans.push_back(it);
	//std::cout << it << " ";
	int nxt;
	if (v[it].first != 0) {
		nxt = v[it].first;
		v[it].first = 0;
	}
	else {
		nxt = v[it].second;
		v[it].second = 0;
	}
	if (v[nxt].first == it) {
		v[nxt].first = 0;
	}
	else {
		v[nxt].second = 0;
	}
	if (nxt != en) {
		make(nxt);
	}
}
int main() {
	std::cin >> n;
	for (int i = 0; i < n; ++i) {
		std::cin >> a >> b;
		if (frst) {
			en = a;
			frst = false;
		}
		if (v[a].first == 0) {
			v[a].first = b;
		}
		else {
			v[a].second = b;
		}
		if (v[b].first == 0) {
			v[b].first = a;
		}
		else {
			v[b].second = a;
		}
	}
	make(en);
	if (ans[2] == 1){
		for (int i = 0; i < n; ++i) {
			std::cout << ans[(n - i) % n] << " ";
		}
	}
	else {
		for (int i = 0; i < n; ++i) {
			std::cout << ans[i] << " ";
		}
	}
}
*/

/*
//1095C
#include <iostream>
#include <vector>
#include <algorithm>
int n, k, p;
std::vector<int> v;
int main() {
	std::cin >> n >> k;
	p = 2;
	while (n > 0) {
		if (n % p) {
			v.push_back(p / 2);
			n -= p / 2;
		}
		p *= 2;
	}
	if (k < v.size()) {
		std::cout << "NO";
		return 0;
	}
	int p = 0;
	while (v.size() < k) {
		while (p < v.size() && v[p] == 1) {
			++p;
		}
		if (p == v.size()) {
			std::cout << "NO";
			return 0;
		}
		v[p] /= 2;
		v.push_back(v[p]);
	}
	std::sort(v.begin(), v.end());
	std::cout << "YES\n";
	for (auto el : v) {
		std::cout << el << " ";
	}
}
*/

/*
//1091C
#include <iostream>
#include <set>
std::set<long long> ans;
int n;
int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);
	std::cin >> n;
	for (int i = 1; i * i <= n; ++i) {
		if (n % i == 0) {
			long long lo = (long long)(1 + (n - i + 1))*(n / i) / 2;
			ans.insert(lo);
			if (i != n / i) {
				long long lo = (long long)(1 + (n - n / i + 1))* i / 2;
				ans.insert(lo);
			}
		}
	}
	for (auto el : ans) {
		std::cout << el << " ";
	}
}
*/

/*
//1091B	--1200
#include <iostream>
#include <map>
std::map<std::pair<int, int>, int> m;
int n, x[1007], y[1007], a[1007], b[1007];
int main() {
	std::cin >> n;
	for (int i = 0; i < n; ++i) {
		std::cin >> x[i] >> y[i];
	}
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i] >> b[i];
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			m[std::make_pair(x[i] + a[j], y[i] + b[j])]++;
		}
	}
	for (auto el : m) {
		if (el.second == n) {
			std::cout << el.first.first << " " << el.first.second;
			break;
		}
	}
}
*/

/*
//1091A --900
#include <iostream>
#include <algorithm>
int y, b, r, ans;
int main() {
	std::cin >> y >> b >> r;
	ans = y;
	ans = std::min(ans + 1, b);
	ans = std::min(ans + 1, r);
	std::cout << ans * 3 - 3;
}
*/

/*
//954D --1600
#include <iostream>
#include <vector>
#include <algorithm>
std::vector<int> V[1007];
const int inf = 1000000;
int n, m, s, t, v, u, dis[2][1007], ans;
bool was[1007][1007];
void make(int start, int* mas) {
	std::vector< int > qu;
	for (int i = 0; i < n; ++i) {
		mas[i] = inf;
	}
	mas[start] = 0;
	qu.push_back(start);
	for (int i = 0; i < qu.size(); ++i) {
		for (int el : V[qu[i]]) {
			if (mas[el] != inf) {
				continue;
			}
			mas[el] = mas[qu[i]] + 1;
			qu.push_back(el);
		}
	}
}
int main() {
	std::cin >> n >> m >> s >> t;
	--s; --t;
	for (int i = 0; i < m; ++i) {
		std::cin >> u >> v;
		--u; --v;
		was[u][v] = was[v][u] = true;
		V[u].push_back(v);
		V[v].push_back(u);
	}
	make(s, dis[0]);
	make(t, dis[1]);
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			if (!was[i][j]) {
				int a1 = dis[0][i] + dis[1][j] + 1;
				int a2 = dis[0][j] + dis[1][i] + 1;
				if (std::min(a1, a2) < dis[0][t]) {
					continue;
				}
				++ans;
			}
		}
	}
	std::cout << ans;
}
*/

/*
//928A	--1600
#include <iostream>
#include <string>
#include <algorithm>
std::string s, f;
int n;
bool ok = true;
int main() {
	std::cin >> s >> n;
	std::transform(s.begin(), s.end(), s.begin(), ::tolower);
	for (int i = 0; i < n; ++i) {
		std::cin >> f;
		std::transform(f.begin(), f.end(), f.begin(), ::tolower);
		if (f.size() != s.size() || !ok) {
			continue;
		}
		ok = false;
		for (int j = 0; j < s.size(); ++j) {
			if (s[j] == f[j]) {
				continue;
			}
			if ((f[j] == 'o' && s[j] == '0') || (s[j] == 'o' && f[j] == '0')) {
				continue;
			}
			if (s[j] == '1' && (f[j] == 'l' || f[j] == 'i')) {
				continue;
			}
			if (s[j] == 'l' && (f[j] == '1' || f[j] == 'i')) {
				continue;
			}
			if (s[j] == 'i' && (f[j] == 'l' || f[j] == '1')) {
				continue;
			}
			ok = true;
			break;
		}
	}
	std::cout << (ok ? "Yes" : "No");
}
*/

/*
//НАДО на другом языке отправлять -_-
//926C
#include <iostream>
int n, a[100007], sz = 1, it;
int main() {
	std::cin >> n;
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
	}
	while (sz < n && a[sz] == a[sz - 1]) {
		++sz;
	}
	if (n % sz != 0) {
		std::cout << "NO";
		return 0;
	}
	for (int i = 1; i < n / sz; ++i) {
		for (int j = 0; j < sz; ++j) {
			if (a[j] != (a[i*sz + j] + i) % 2) {
				std::cout << "NO";
				return 0;
			}
		}
	}
	std::cout << "YES";
}
*/

/*
//926A	--1300
#include <iostream>
#include <set>
const int inf = 2000000000;
int l, r, ans;
std::set<int> s;
int main() {
	std::cin >> l >> r;
	long long a = 1;
	for (int i = 0; true; ++i) {
		long long b = a;
		for (int j = 0; true; ++j) {
			s.insert(b);
			b *= 3;
			if (b > inf)
				break;
		}
		a *= 2;
		if (a > inf)
			break;
	}
	for (auto el : s) {
		if (l <= el && el <= r) {
			++ans;
		}
	}
	std::cout << ans;
}
*/

/*
//924B	--1600
#include <iostream>
#include <algorithm>
int n, U, E[100007], it;
double ans = -1;
int main() {
	std::cin >> n >> U;
	for (int i = 1; i <= n; ++i) {
		std::cin >> E[i];
	}
	for (int i = 1, k = 1, j; i <= n; ++i) {
		while (k < n && E[k + 1] - E[i] <= U) {
			++k;
		}
		j = i + 1;
		if (j < k) {
			double l = (double)(E[k] - E[j]) / (E[k] - E[i]);
			ans = std::max(ans, l);
		}
	}
	std::cout.precision(12);
	std::cout << ans;
}
*/

/*
//916C	--1600
#include <iostream>
int n, m, it;
int main() {
	std::cin >> n >> m;
	it = 100003;
	std::cout << it << " " << it << "\n";
	std::cout << "1 2 " << it - (n - 1) + 1 << "\n";
	for (int i = 2; i < n; ++i) {
		std::cout << i << " " << i + 1 << " 1\n";
	}
	m -= n - 1;
	for (int i = 1; i < n && m > 0; ++i) {
		for (int j = i + 2; j <= n && m > 0; ++j) {
			std::cout << i << " " << j << " 1000000000\n";
			--m;
		}
	}
}
*/

/*
//1100D
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

//#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);


int x[667], y[667], X, Y, a[1007][1007], st[4], mn;
bool ok = false;
void getinfo() {
	int k, b, c;
	cin >> k >> b >> c;
	if (k <= 0) exit(0);
	a[x[k]][y[k]] = 0;
	x[k] = b;
	y[k] = c;
	a[x[k]][y[k]] = 1;
}

void putinfo() {
	cout << x[0] << " " << y[0] << endl;
	cout.flush();
	fflush(stdout);
}

int checkSZ(int X, int Y) {
	int SZ = 0;
	for (int i = 1; i < 500; ++i) {
		for (int j = 1; j < 500; ++j) {
			int X0 = x[0] + X * i;
			int Y0 = y[0] + Y * j;
			SZ += a[X0][Y0];
		}
	}
	return SZ;
}

void check(int X, int Y) {
	for (int i = 1; i < 500; ++i) {
		if (a[x[0] + X][y[0] + Y] == 1) {
			X = 0;
		}
		x[0] += X;
		y[0] += Y;
		putinfo();
		getinfo();
	}
}

int main() {
	//IOS;
	cin >> x[0] >> y[0];
	for (int i = 1; i < 667; ++i) {
		cin >> x[i] >> y[i];
		a[x[i]][y[i]] = 1;
	}
	while (x[0] != 500 || y[0] != 500) {
		if (x[0] != 500)
			X = (500 - x[0]) / abs(500 - x[0]);
		else X = 0;
		if (y[0] != 500)
			Y = (500 - y[0]) / abs(500 - y[0]);
		else Y = 0;
		if (a[x[0] + X][y[0] + Y] == 1) {
			X = 0;
		}
		x[0] += X;
		y[0] += Y;
		putinfo();
		getinfo();
	}
	st[0] = checkSZ(1, 1);
	st[1] = checkSZ(1, -1);
	st[2] = checkSZ(-1, 1);
	st[3] = checkSZ(-1, -1);
	mn = min(st[0], min(st[1], min(st[2], st[3])));

	if (st[0] == mn)	check(-1, -1);
	if (st[1] == mn)	check(-1, 1);
	if (st[2] == mn)	check(1, -1);
	if (st[3] == mn)	check(1, 1);

	return 0;
}
*/

/*
//1100C
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <math.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int n, r, R;
int main() {
	IOS;
	cin >> n >> r;
	cout.precision(12);
	double pi = 3.14159265358979323846;
	double sina = sin((double)pi / n);
	double R = (double)r*sina / ((double)1 - sina);
	cout << R;
	return 0;
}
*/


/*
//1100B
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int n, m, a, cnt, was[100007];
string ans = "";
int main() {
	IOS;
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		cin >> a;
		if (was[a] == 0) {
			++cnt;
		}
		++was[a];
		if (cnt == n) {
			for (int i = 1; i <= n; ++i) {
				--was[i];
				if (was[i] == 0) {
					--cnt;
				}
			}
			ans += "1";
		}
		else {
			ans += "0";
		}
	}
	cout << ans;
	return 0;
}
*/

/*
//1100A
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int n, k, a[300], b[300], s;
int main() {
	IOS;
	cin >> n >> k;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		s += a[i];
	}
	for (int i = 0; i < k; ++i) {
		int j = i;
		while (j < n) {
			b[i] += a[j];
			j += k;
		}
		b[i] = abs(s - b[i]);
	}
	cout << *max_element(b, b + k);
	return 0;
}
*/

/*
//1101E
#include <iostream>
#include <algorithm>
int n, x, y, h, w;
char q;
int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);
	std::cin >> n;
	for (int i = 0; i < n; ++i) {
		std::cin >> q >> x >> y;
		if (q == '+') {
			h = std::max(h, std::max(x, y));
			w = std::max(w, std::min(x, y));
		}
		else {
			if (h > std::max(x, y) || w > std::min(x, y)) {
				std::cout << "NO\n";
			}
			else {
				std::cout << "YES\n";
			}
		}
	}
}
*/

/*
//1095B
#include <iostream>
#include <algorithm>
int n, a[100007];
int main() {
	std::cin >> n;
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
	}
	std::sort(a, a + n);
	std::cout << std::min(a[n - 2] - a[0], a[n - 1] - a[1]);
}
*/

/*
//1099B
#include <iostream>
int n, k = 1, ans;
int main() {
	std::cin >> n;
	while ((k + 1)*(k + 1) < n) {
		++k;
	}
	if (k*k == n) {
		ans = k * 2;
	}
	else if (k*k + k >= n) {
		ans = k * 2 + 1;
	}
	else {
		ans = k * 2 + 2;
	}
	std::cout << ans;
}
*/

/*
//1099C
#include <iostream>
#include <string>
int k, n;
char old = '*';
std::string s, ans;
int main() {
	std::cin >> s >> k;
	for (auto el : s) {
		if (el != '?' && el != '*') {
			++n;
		}
	}
	for (auto el : s) {
		if (el == '?') {
			if (n <= k) {
				ans += old;
			}
			else {
				--n;
			}
		}
		else if (el == '*') {
			if (n <= k) {
				for (int i = 0; i <= k - n; ++i) {
					ans += old;
				}
				n = k;
			}
			else {
				--n;
			}
		}
		else if (old != '*' && old != '?') {
			ans += old;
		}
		old = el;
	}
	if (s[s.size() - 1] != '?' && s[s.size() - 1] != '*') {
		ans += s[s.size() - 1];
	}
	std::cout << (n == k ? ans : "Impossible");
}
*/

/*
//1102B
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
int n, k, a[5007], ans[5007], it;
std::vector<std::pair<int, int>> v(5007);
std::map<int, int> m;
int main() {
	std::cin >> n >> k;
	for (int i = 0; i < n; ++i) {
		std::cin >> v[i].first;
		v[i].second = i;
		a[v[i].first]++;
	}
	for (int i = 1; i <= 5000; ++i) {
		if (a[i] > k) {
			std::cout << "NO";
			return 0;
		}
	}
	std::cout << "YES\n";
	std::sort(v.begin(), v.begin() + n);
	for (int i = 0; i < n; ++i) {
		if (a[v[i].first] != k) {
			ans[v[i].second] = it + 1;
			it = (it + 1) % k;
		}
		else {
			ans[v[i].second] = m[v[i].first]++ + 1;
		}
	}
	for (int i = 0; i < n; ++i) {
		std::cout << ans[i] << " ";
	}
}
*/

/*
//1102D
#include <iostream>
#include <string>
std::string s;
int n, c[3], d[3];
int main() {
	std::cin >> n >> s;
	for (int i = 0; i < n; ++i) {
		c[s[i] - '0']++;
	}
	for (int i = 0; i < n; ++i) {
		d[s[i] - '0']++;
		if (c[s[i] - '0'] > n / 3) {
			bool ok = false;
			for (int j = 0; j < s[i] - '0'; ++j) {
				if (c[j] < n / 3) {
					ok = true;
					break;
				}
			}
			if (!(ok || d[s[i] - '0'] > n / 3))
				continue;
			for (int j = 0; j < 3; ++j) {
				if (j == s[i] - '0' || c[j] >= n / 3)
					continue;
				c[s[i] - '0']--;
				c[j]++;
				d[s[i] - '0']--;
				d[j]++;
				s[i] = '0' + j;
				break;
			}
		}
	}
	std::cout << s;
}
*/

/*
//1099A
#include <iostream>
int w, h, u[2], d[2];
int main() {
	std::cin >> w >> h >> u[0] >> d[0] >> u[1] >> d[1];
	while (h > 0) {
		w += h;
		for (int i = 0; i < 2; ++i) {
			if (h == d[i]) {
				w -= u[i];
			}
		}
		if (w < 0) {
			w = 0;
		}
		--h;
	}
	std::cout << w;
}
*/

/*
//1095A
#include <iostream>
int n;
char q;
int main() {
	std::cin >> n;
	for (int i = 0, j = 1; i < n; ++i, ++j) {
		for (int k = 0; k < j; ++k, ++i) {
			std::cin >> q;
		}
		std::cout << q;
	}
}
*/

/*
//1097A
#include <iostream>
#include <string>

std::string a, b;
bool ans = false;
int main() {
	std::cin >> a;
	for (int i = 0; i < 5; ++i) {
		std::cin >> b;
		if (a[0] == b[0] || a[1] == b[1]) {
			ans = true;
		}
	}
	std::cout << (ans ? "YES" : "NO");
}
*/

/*
//1102C
#include  <iostream>
#include <algorithm>
int n, x, y, a[107], ans;
int main() {
	std::cin >> n >> x >> y;
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
	}
	if (x > y) {
		ans = n;
	}
	else {
		std::sort(a, a + n);
		for (int i = 0; i < n && a[i] <= x; ++i) {
			if (i % 2 == 0) {
				++ans;
			}
		}
	}
	std::cout << ans;
}
*/

/*
//1102A
#include <iostream>

long long n;
int main() {
	std::cin >> n;
	std::cout << (n * (n + 1) / 2) % 2;
}
*/

/*
//1096D
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

string s;
int n, a[100007];
int main() {
	IOS;
	cin >> n >> s;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	return 0;
}
*/


/*
//1096C
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int T, ang, talf, n, i, coef;
int main() {
	IOS;
	cin >> T;
	for (int t = 0; t < T; ++t) {
		cin >> ang;
		//ang = t;
		//cout << t << " ";
		if (ang == 179) {
			cout << "360\n";
			continue;
		}
		for (i = 3; i <= 180; ++i) {
			if ((180 * (i - 2)) % i != 0) continue;
			talf = 180 * (i - 2) / i;
			if (talf % 2) {
				talf = 180 - talf;
				coef = 2;
			}
			else {
				talf = (180 - talf) / 2;
				coef = 1;
			}
			if (ang % talf == 0 && (ang / talf) * coef <= i - 2) {
				cout << i << "\n";
				break;
			}
		}
	}
	return 0;
}
*/


/*
//1096B
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

const int inf = 998244353;
string s;
long long n, a, b;
int main() {
	IOS;
	cin >> n >> s;
	if (s[0] == s[n - 1]) {
		a = 1;
		while (a != n && s[a] == s[a - 1]) ++a;
		b = n - 2;
		while (s[b] == s[b + 1]) --b;
		b = n - 1 - b;
		cout << ((a + 1) * (b + 1)) % inf;
	}
	else {
		a = 1;
		while (s[a] == s[a - 1]) ++a;
		b = n - 2;
		while (s[b] == s[b + 1]) --b;
		b = n - 1 - b;
		cout << (a + b + 1) % inf;
	}
	return 0;
}
*/

/*
//1096A
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
long long T, l, r;
int main() {
	IOS;
	cin >> T;
	for (int i = 0; i < T; ++i) {
		cin >> l >> r;
		if (2 * l <= r) {
			cout << l << " " << l * 2 << "\n";
		}
	}
	return 0;
}
*/

/*
//976C
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

bool cmp(std::pair< std::pair< int, int >, int > const &a, std::pair< std::pair< int, int >, int > const &b) {
	if (a.first.first == b.first.first)
		return a.first.second > b.first.second;
	return a.first.first < b.first.first;
}
int n, l, r;
std::vector< std::pair< std::pair< int, int >, int > > v;
int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);
	std::cin >> n;
	for (int i = 1; i <= n; ++i) {
		std::cin >> l >> r;
		v.push_back(std::make_pair(std::make_pair(l, r), i));
	}
	std::sort(v.begin(), v.end(), cmp);
	std::set<std::pair< int, int >> cur;
	for (int i = 0; i < n; ++i) {
		while (!cur.empty() && cur.begin()->first < v[i].first.first)
			cur.erase(cur.begin());
		if (!cur.empty() && (--cur.end())->first >= v[i].first.second) {
			printf("%d %d\n", v[i].second, (--cur.end())->second);
			return 0;
		}
		cur.insert({ v[i].first.second, v[i].second });
	}
	std::cout << "-1 -1";
}
*/

/*
//WRONG
//976C
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

int n, l, r;
std::set< int > opened;
struct point {
	point(int pos, int len, bool open, int id)
		: pos(pos), len(len), open(open), id(id) {}
	int pos;
	int len;
	bool open;
	int id;
	bool operator<(point const &oth) {
		if (pos == oth.pos) {
			if (open == oth.open) {
				if (len != oth.len) {
					if (open) {
						return len > oth.len;
					}
					else {
						return len < oth.len;
					}
				}
				else {
					if (open) {
						return id > oth.id;
					}
					else {
						return id < oth.id;
					}
				}
			}
			else {
				if (id == oth.id) {
					return open > oth.open;
				}
				else {
					return open < oth.open;
				}
			}
		}
		return pos < oth.pos;
	}
};
std::vector< point > v;
std::set< int > st[300007];
int main() {
	std::cin >> n;
	for (int i = 1; i <= n; ++i) {
		std::cin >> l >> r;
		v.push_back(point(l, r - l, true, i));
		v.push_back(point(r, r - l, false, i));
	}
	std::sort(v.begin(), v.end());
	for (int i = 0; i < n * 2; ++i) {
		if (v[i].open) {
			for (int el : opened) {
				st[v[i].id].insert(el);
			}
			opened.insert(v[i].id);
		}
		else {
			opened.erase(v[i].id);
			for (auto x : st[v[i].id]) {
				if (opened.count(x)) {
					std::cout << v[i].id << " " << x;
					return 0;
				}

			}
		}
	}
	std::cout << "-1 -1";
}
*/

/*
//978D	--1500
#include <iostream>

int n, q[100007], ans = 100007;
int main() {
	std::cin >> n;
	for (int i = 0; i < n; ++i) {
		std::cin >> q[i];
	}
	if (n < 3) {
		std::cout << 0;
		return 0;
	}
	for (int a = -1; a < 2; ++a) {
		for (int b = -1; b < 2; ++b) {
			for (int c = -1; c < 2; ++c) {
				int A = q[0] + a, B = q[1] + b, C = q[2] + c, D;
				if (B - A != C - B) continue;
				int lans = (a ? 1 : 0) + (b ? 1 : 0) + (c ? 1 : 0);
				bool ok = true;
				for (int i = 3; i < n && ok; ++i) {
					ok = false;
					for (int d = -1; d < 2; ++d) {
						D = q[i] + d;
						if (D - C == B - A) {
							ok = true;
							if (d != 0) ++lans;
							C = D;
							break;
						}
					}
				}
				if (ok && lans < ans) {
					ans = lans;
				}
			}
		}
	}
	std::cout << (ans == 100007 ? -1 : ans);
}
*/

/*
//978F
#include <iostream>
#include <vector>
#include <algorithm>

int n, k, x, y, s[200007], ans[200007], offset;
std::vector< std::pair<int, int> > r(1);
int main() {
	std::cin >> n >> k;
	for (int i = 1; i <= n; ++i) {
		std::cin >> x;
		r.push_back(std::make_pair(x, i));
	}
	for (int i = 0; i < k; ++i) {
		std::cin >> x >> y;
		if (r[x].first == r[y].first) continue;
		if (r[x].first < r[y].first) {
			s[y]++;
		}
		else {
			s[x]++;
		}
	}
	std::sort(r.begin() + 1, r.end());
	for (int i = 1; i <= n; ++i) {
		if (r[i].first == r[i - 1].first) {
			++offset;
		}
		else {
			offset = 0;
		}
		ans[r[i].second] = i - 1 - s[r[i].second] - offset;
	}
	for (int i = 1; i <= n; ++i) {
		std::cout << ans[i] << " ";
	}
}
*/

/*
//979C
#include <iostream>
#include <vector>

int n, x, y, a, b, q[300007], cntQ;
long long ans;
bool was[300007];
std::vector< int > g[300007];
int make(int x, int y) {
	for (int i = 1; i <= n; ++i) {
		was[i] = false;
	}
	cntQ = 0;
	q[cntQ++] = x;
	for (int i = 0; i < cntQ; ++i) {
		int v = q[i];
		was[v] = true;
		for (int u : g[v]) {
			if (u == y || was[u]) continue;
			q[cntQ++] = u;
		}
	}
	return cntQ;
}
long long f(long long x) {
	return (x - 1)*x / 2;
}
int main() {
	std::cin >> n >> x >> y;
	for (int i = 1; i < n; ++i) {
		std::cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	a = make(x, y);
	b = make(y, x);

	ans = f(n) + f(a) + f(b) - f(a + b - n);
	std::cout << ans;
}
*/

/*
//982C	--1500
#include <iostream>
#include <map>
#include <set>

std::map< int, std::set< int > > m;
int n, u, v, ans;
bool was[100007];

int make(int it) {
	was[it] = true;
	int rez = 1;
	for (auto el : m[it]) {
		if (!was[el]) {
			rez += make(el);
		}
	}
	if (rez % 2 == 0) {
		++ans;
		return 0;
	}
	return 1;
}
int main() {
	std::cin >> n;
	for (int i = 1; i < n; ++i) {
		std::cin >> u >> v;
		m[v].insert(u);
		m[u].insert(v);
	}

	std::cout << (make(1) % 2 ? -1 : ans-1);
}
*/

/*
//981C
#include <iostream>
#include <vector>
#include <map>

std::vector< int > g[100007];
std::map< int, int > m;
int n, u, v, aim = -1;
int main() {
	std::cin >> n;
	for (int i = 0; i < n - 1; ++i) {
		std::cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for (int i = 1; i <= n; ++i) {
		m[g[i].size()]++;
	}
	for (auto el : m) {
		if (el.first > 2) {
			if (aim < 0 && el.second == 1) {
				aim = el.first;
			}
			else {
				std::cout << "No";
				return 0;
			}
		}
	}
	std::cout << "Yes\n";
	if (aim < 0) {
		std::cout << "1\n";
		for (int i = 1; i <= n; ++i) {
			if (g[i].size() == 1) {
				std::cout << i << " ";
			}
		}
	}
	else {
		std::cout << m[1] << "\n";
		for (int i = 1; i <= n; ++i) {
			if (g[i].size() == aim) {
				aim = i;
				break;
			}
		}
		for (int i = 1; i <= n; ++i) {
			if (g[i].size() == 1) {
				std::cout << aim << " " << i << "\n";
			}
		}
	}
}
*/

/*
//986A
#include <iostream>
#include <vector>
#include <algorithm>

const int inf = 100007;
int n, m, k, s, ans[inf][107], dist[inf], q[inf];
std::vector< int > color[107], v[inf];
int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);
	std::cin >> n >> m >> k >> s;
	for (int i = 0; i < n; ++i) {
		int t;
		std::cin >> t;
		color[--t].push_back(i);
	}
	for (int i = 0; i < m; ++i) {
		int u, w;
		std::cin >> u >> w;
		--u, --w;
		v[u].push_back(w);
		v[w].push_back(u);
	}
	for (int kx = 0; kx < k; ++kx) {
		for (int i = 0; i < n; ++i) {
			dist[i] = inf;
		}
		int topQ = 0;
		for (int i : color[kx]) {
			dist[i] = 0;
			q[topQ++] = i;
		}
		for (int i = 0; i < topQ; ++i) {
			int el = q[i];
			for (int u : v[el]) {
				if (dist[u] <= dist[el] + 1) continue;
				dist[u] = dist[el] + 1;
				q[topQ++] = u;
			}
		}
		for (int i = 0; i < n; ++i) {
			ans[i][kx] = dist[i];
		}
	}
	for (int i = 0; i < n; ++i) {
		std::nth_element(ans[i], ans[i] + s, ans[i] + k);
		int rez = 0;
		for (int j = 0; j < s; ++j) {
			rez += ans[i][j];
		}
		std::cout << rez << " ";
	}
}
*/

/*
//WRONG
//986A
#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

std::vector< std::vector< int > > vc;
int n, m, k, s, a[100007], u, v;
std::map< int, std::set< int > > st;
std::queue< std::pair< int, int > > q[107];
int main() {
	std::cin >> n >> m >> k >> s;
	for (int i = 1; i <= n; ++i) {
		std::cin >> a[i];
		q[a[i]].push(std::make_pair(i, 0));
	}
	for (int i = 0; i < m; ++i) {
		std::cin >> u >> v;
		st[u].insert(v);
		st[v].insert(u);
	}
	for (int i = 0; i <= n; ++i) {
		vc.push_back(std::vector< int >(k + 1, n));
	}
	for (int i = 1; i <= k; ++i) {
		std::vector< bool > was(n + 1, false);
		while (!q[i].empty()) {
			std::pair< int, int > el = q[i].front();
			q[i].pop();
			was[el.first] = true;
			vc[el.first][i] = std::min(vc[el.first][i], el.second);
			for (auto it : st[el.first]) {
				if (!was[it]) {
					q[i].push(std::make_pair(it, el.second + 1));
				}
			}
		}
	}
	for (int i = 1; i <= n; ++i) {
		std::sort(vc[i].begin() + 1, vc[i].end());
		long long ans = 0;
		for (int j = 1; j <= s; ++j) {
			ans += vc[i][j];
		}
		std::cout << ans << " ";
	}
}
*/

/*
//965B
#include <iostream>
#include <string>
#include <algorithm>

std::string s[107];
int n, k, a[107][107][2], b[107][107][2], mx, x = 1, y = 1;
int main() {
	std::cin >> n >> k;
	for (int i = 0; i < n; ++i) {
		std::cin >> s[i];
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (s[i][j] == '.') {
				a[i + 1][j + 1][0] += std::min(a[i][j + 1][0] + 1, k);
				b[i + 1][j + 1][0] += std::min(b[i + 1][j][0] + 1, k);
			}
		}
	}
	for (int i = n-1; i >=0; --i) {
		for (int j = n-1; j >= 0; --j) {
			if (s[i][j] == '.') {
				a[i + 1][j + 1][1] += std::min(a[i + 2][j + 1][1] + 1, k);
				b[i + 1][j + 1][1] += std::min(b[i + 1][j + 2][1] + 1, k);
			}
		}
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (std::max(a[i][j][0] + a[i][j][1] - k, 0) + std::max(b[i][j][0] + b[i][j][1] - k, 0) > mx) {
				mx = std::max(a[i][j][0] + a[i][j][1] - k, 0) + std::max(b[i][j][0] + b[i][j][1] - k, 0);
				x = i;
				y = j;
			}
		}
	}
	std::cout << x << " " << y;
}
*/

/*
//1081A
#include <iostream>

int v;
int main() {
	std::cin >> v;
	for (int i = v - 1; i > 1; --i) {
		if (v%i) {
			v -= i;
			break;
		}
	}
	std::cout << v;
}
*/

/*
//1081B
#include <iostream>
#include <vector>
#include <map>

std::vector< int > a(100007), b(100007);
std::map< int, std::vector< int > > m;
int n, t;
bool ok = true;
int main() {
	std::cin >> n;
	for (int i = 1; i <= n; ++i) {
		std::cin >> t;
		++a[n - t];
		m[n - t].push_back(i);
	}
	for (int i = 1, k = 1; i <= n; ++i) {
		if (a[i] % i != 0) {
			ok = false;
			break;
		}
		for (int k0 = 0, j = 0; k0 < a[i] / i; ++k0) {
			for (int j0 = 0; j0 < i; ++j0, ++j) {
				b[m[i][j]] = k;
			}
			++k;
		}
	}
	if (!ok) {
		std::cout << "Impossible";
	}
	else {
		std::cout << "Possible\n";
		for (int i = 1; i <= n; ++i) {
			std::cout << b[i] << " ";
		}
	}
}
*/

/*
//1081C
#include <iostream>

const int inf = 998244353;

long long n, m, k, f[2007][2007];
int main() {
	std::cin >> n >> m >> k;
	f[1][0] = m;

	for (int i = 1; i < n; ++i) {
		for (int j = 0; j <= k; ++j) {
			(f[i + 1][j] += f[i][j]) %= inf;
			(f[i + 1][j + 1] += f[i][j] * (m - 1)) %= inf;
		}
	}
	std::cout << f[n][k];
}
*/

/*
//1087C
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

pair<int, int> xt;
vector< pair<int, int> > X;
set<pair<int, int>> s[12];
pair<int,int> f(int x, int y, int c, int d, int it) {
	return make_pair(abs(x - c) + abs(y - d) - 1, it);
}
void make(int i1, int i2, int it) {
	int x = X[i1].first, y = X[i1].second, c = X[i2].first, d = X[i2].second;

	if ((x - c > 0) == (y - d > 0)) {
		for (int i = min(x, c) + 1; i < max(x, c); ++i) {
			s[it].insert(make_pair(i, min(y, d)));
		}
		for (int i = min(y, d) + 1; i < max(y, d); ++i) {
			s[it].insert(make_pair(max(x, c), i));
		}
		if (x == c || y == d) {
			return;
		}
		s[it].insert(make_pair(max(x, c), min(y, d)));
	}
	else {
		for (int i = min(x, c) + 1; i < max(x, c); ++i) {
			s[it].insert(make_pair(i, min(y, d)));
		}
		for (int i = min(y, d) + 1; i < max(y, d); ++i) {
			s[it].insert(make_pair(min(x, c), i));
		}
		if (x == c || y == d) {
			return;
		}
		s[it].insert(make_pair(min(x, c), min(y, d)));
	}
}
void make2(int i1, int i2, int it) {
	int x = X[i1].first, y = X[i1].second, c = X[i2].first, d = X[i2].second;

	if ((x - c > 0) == (y - d > 0)) {
		for (int i = min(x, c) + 1; i < max(x, c); ++i) {
			s[it].insert(make_pair(i, max(y, d)));
		}
		for (int i = min(y, d) + 1; i < max(y, d); ++i) {
			s[it].insert(make_pair(min(x, c), i));
		}
		if (x == c || y == d) {
			return;
		}
		s[it].insert(make_pair(min(x, c), max(y, d)));
	}
	else {
		for (int i = min(x, c) + 1; i < max(x, c); ++i) {
			s[it].insert(make_pair(i, max(y, d)));
		}
		for (int i = min(y, d) + 1; i < max(y, d); ++i) {
			s[it].insert(make_pair(max(x, c), i));
		}
		if (x == c || y == d) {
			return;
		}
		s[it].insert(make_pair(max(x, c), max(y, d)));
	}
}
int main() {
	IOS;
	for (int i = 0; i < 3; ++i) {
		cin >> xt.first >> xt.second;
		X.push_back(xt);
	}
	sort(X.begin(), X.end());


	make(0, 1, 0);
	make(0, 2, 0);

	make(0, 1, 1);
	make2(0, 2, 1);

	make2(0, 1, 2);
	make(0, 2, 2);

	make2(0, 1, 3);
	make2(0, 2, 3);



	make(1, 0, 4);
	make(1, 2, 4);

	make(1, 0, 5);
	make2(1, 2, 5);

	make2(1, 0, 6);
	make(1, 2, 6);

	make2(1, 0, 7);
	make2(1, 2, 7);



	make(2, 1, 8);
	make(2, 0, 8);

	make(2, 1, 9);
	make2(2, 0, 9);

	make2(2, 1, 10);
	make(2, 0, 10);

	make2(2, 1, 11);
	make2(2, 0, 11);


	int ita = 0, its = 1000000;
	for (int i = 0; i < 12; ++i) {
		if (s[i].size() < its) {
			its = s[i].size();
			ita = i;
		}
	}

	cout << s[ita].size() + 3 << "\n";
	for (auto el : s[ita]) {
		cout << el.first << " " << el.second << "\n";
	}

	for (int i = 0; i < 3; ++i) {
		cout << X[i].first << " " << X[i].second << "\n";
	}
	return 0;
}
*/

/*
//1087B
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int k, n, x = 1000000000;
int main() {
	IOS;
	cin >> n >> k;

	for (int i = 1; i < k; ++i) {
		if (n%i == 0) {
			if (i + k < x) {
				x = i + k * (n / i);
			}
		}
	}
	cout << x;

	return 0;
}
*/

/*
//1087A
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int l, r;
string s, ans;
int main() {
	IOS;
	cin >> s;
	l = 0; r = s.size() - 1;
	for (int i = 0; i < s.size(); ++i) {
		if ((s.size() + i) % 2) {
			ans = s[l++] + ans;
		}
		else {
			ans = s[r--] + ans;;
		}
	}
	cout << ans;

	return 0;
}
*/

/*
//WRONG
//982C	--1500
#include <iostream>
#include <map>
#include <set>
std::map< int, std::set< int > > m;
int n, u, v, ans;
bool was[100007];

int make(std::set<int> &s, int it) {
	if (was[it]) {
		return 0;
	}
	s.insert(it);
	was[it] = true;
	int rez = 0;
	for (int el : m[it]) {
		rez += make(s, el) + 1;
		s.insert(el);
	}
	return rez;
}
int main() {
	std::cin >> n;
	for (int i = 1; i < n; ++i) {
		std::cin >> u >> v;
		m[v].insert(u);
		m[u].insert(v);
	}
	for (int i = 1; i <= n; ++i) {
		if (!was[i]) {
			std::set< int > s;
			int rbr = make(s, i) / 2, p;
			if (s.size() % 2) {
				std::cout << -1;
				return 0;
			}
			p = s.size();
			if (p != 2) {
				for (int el : s) {
					if (m[el].size() == 1) {
						--rbr;
						--p;
					}
				}
				rbr += 2;
				p += 2;
				if (rbr - p / 2 > 0) {
					ans += rbr - p / 2;
				}
			}
		}
	}
	std::cout << ans;
}
*/

/*
//991D	--1500
#include <iostream>
#include <string>

std::string s1, s2;
int a[107], ans, i, n;
int main() {
	std::cin >> s1 >> s2;
	n = s1.size();
	for (i = 0; i < n; ++i) {
		a[i] = (s1[i] == 'X' ? 1 : 0) + (s2[i] == 'X' ? 1 : 0);
	}
	a[s1.size()] = 100;
	for (i = 0; i < n - 1; ++i) {
		if (a[i] == 0 && a[i+1] < 2) {
			++ans;
			a[i] += 2;
			a[i + 1] += 1;
		}
		else if (a[i] == 1 && a[i + 1] == 0) {
			++ans;
			a[i] += 1;
			a[i + 1] += 2;
		}
	}
	std::cout << ans;
}
*/

/*
//1033C
#include <iostream>
#include <set>

std::set< int > s[100007];
int n, a[100007], b[100007];
int check(int it, int val) {
	if (b[it] != -1) {
		return b[it];
	}
	for (int el : s[it]) {
		if (check(el, val + 1) == 1) {
			b[it] = 0;
			return b[it];
		}
	}
	b[it] = 1;
	return b[it];
}
int main() {
	std::cin >> n;
	for (int i = 1; i <= n; ++i) {
		std::cin >> a[i];
		b[i] = -1;
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = i - a[i]; j > 0; j -= a[i]) {
			if (a[j] > a[i]) {
				s[i].insert(j);
			}
		}
		for (int j = i + a[i]; j <= n; j += a[i]) {
			if (a[j] > a[i]) {
				s[i].insert(j);
			}
		}
	}
	for (int i = 1; i <= n; ++i) {
		std::cout << (char)('A' + check(i, 0) % 2);
	}
}
*/

/*
//1093D	--1600
#include <iostream>
#include <map>
#include <set>
#include <vector>

const int inf = 998244353;
int t, n, m, u, v, x[2], p2[300007];
long long ans;
int was[300007];
bool ok;

bool make(std::map< int, std::set< int > > &g, int it, int val) {
	was[it] = val;
	++x[val];
	for (auto el : g[it]) {
		if (was[el] < 0) {
			if (!make(g, el, (val + 1) % 2)) {
				return false;
			}
		}
		else {
			if (was[el] == val) {
				ok = false;
				return false;
			}
		}
	}
	return true;
}

int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);
	std::cin >> t;
	p2[0] = 1;
	for (int i = 1; i < 300001; ++i) {
		p2[i] = (p2[i - 1] * 2) % inf;
	}
	for (int i = 0; i < t; ++i) {
		std::map< int, std::set< int > > g;
		std::vector< int > an;
		std::cin >> n >> m;
		ok = true;
		for (int j = 1; j <= n; ++j) {
			was[j] = -1;
		}
		for (int j = 0; j < m; ++j) {
			std::cin >> u >> v;
			g[u].insert(v);
			g[v].insert(u);
		}
		for (int j = 1; j <= n && ok; ++j) {
			if (was[j] < 0) {
				x[0] = 0;
				x[1] = 0;
				ok = true;
				make(g, j, 0);
				if (ok) {
					an.push_back((p2[x[0]] + p2[x[1]]) % inf);
				}
			}
		}
		if (!ok) {
			std::cout << "0\n";
		}
		else {
			ans = 1;
			for (auto el : an) {
				ans = (ans * el) % inf;
			}
			std::cout << ans << "\n";
		}
	}
}
*/

/*
//1093C
#include <iostream>
#include <algorithm>>

long long n, a[200007], b[100007];
int main() {
	std::cin >> n;
	std::cin >> b[1];
	a[n] = b[1];
	a[1] = 0;
	for (int i = 2; i <= n / 2; ++i) {
		std::cin >> b[i];
		a[n - i + 1] = std::min(b[i], a[n - i + 2]);
		a[i] = b[i] - a[n - i + 1];

		if (a[i] < a[i - 1]) {
			a[n - i + 1] -= a[i - 1] - a[i];
			a[i] = a[i - 1];
		}
	}
	for (int i = 1; i <= n; ++i) {
		std::cout << a[i] << " ";
	}
}
*/

/*
//1093B
#include <iostream>
#include <string>
#include <map>

int t;
std::string s;
int main() {
	std::cin >> t;
	for (int i = 0; i < t; ++i) {
		std::map<char, int > m;
		std::cin >> s;
		for (int j = 0; j < s.size(); ++j) {
			++m[s[j]];
		}
		if (m.size() == 1) {
			std::cout << "-1\n";
		}
		else {
			for (auto el : m) {
				for (int j = 0; j < el.second; ++j) {
					std::cout << el.first;
				}
			}
			std::cout << "\n";
		}

	}
}
*/

/*
//1093A
#include <iostream>

int t, x;
int main() {
	std::cin >> t;
	for (int i = 0; i < t; ++i) {
		std::cin >> x;
		for (int j = 2; j <= 7; ++j) {
			if (x%j != 1) {
				std::cout << x / j + (x%j ? 1 : 0) << "\n";
				break;
			}
		}
	}
}
*/

/*
//1092D1
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <stack>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int n, a[200007];
bool ok = true;
void make() {
	stack< int> st;
	for (int i = 0; i < n && ok; ++i) {
		if (!st.size() || st.top() != a[i]) {
			//if (st.size() && st.top() < a[i]) {
			//	ok = false;
			//}
			st.push(a[i]);
		}
		else {
			st.pop();
		}
	}
	if (st.size() > 1) {
		ok = false;
	}
}
int main() {
	IOS;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		a[i] = a[i] % 2;
	}
	make();
	reverse(a, a + n);
	make();
	cout << (ok ? "YES" : "NO");

	return 0;
}
*/

/*
//1092F
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int n, a[200007], u, v;
map <int, map< int, pair<long long, long long> > > m;
bool was[200007], was2[200007];
long long ans;

pair<long long, long long> make(int it) {
	was[it] = true;
	pair<long long, long long> rez(a[it], a[it]);
	for (auto el : m[it]) {
		if (!was[el.first]) {
			m[it][el.first] = make(el.first);
			rez.first += m[it][el.first].first;
			rez.second += m[it][el.first].second + m[it][el.first].first;
		}
	}
	return rez;
}

void find_max(int it) {
	was2[it] = true;
	pair<long long, long long> lans = make_pair(0, 0);
	for (auto el : m[it]) {
		lans.first += el.second.first;
		lans.second += el.second.second;
	}
	ans = max(ans, lans.second);

	for (auto el : m[it]) {
		if (!was2[el.first]) {
			m[el.first][it].first = lans.first - m[it][el.first].first + a[it];
			m[el.first][it].second = lans.second - m[it][el.first].second + m[el.first][it].first;
			find_max(el.first);
		}
	}
}

int main() {
	IOS;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	for (int i = 0; i < n - 1; ++i) {
		cin >> u >> v;
		m[u][v] = make_pair(0, 0);
		m[v][u] = make_pair(0, 0);
	}
	int it = 1;
	make(it);
	find_max(it);
	std::cout << ans;
	return 0;
}
*/


/*
//1092D2
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <stack>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int n, a[200007];
bool ok = true;
void make() {
	stack< int> st;
	for (int i = 0; i < n && ok; ++i) {
		if (!st.size() || st.top() != a[i]) {
			if (st.size() && st.top() < a[i]) {
				ok = false;
			}
			st.push(a[i]);
		}
		else {
			st.pop();
		}
	}
	if (st.size() > 1) {
		ok = false;
	}
}
int main() {
	IOS;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	make();
	reverse(a, a + n);
	make();
	cout << (ok ? "YES" : "NO");

	return 0;
}
*/




/*
//1092C
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int n, was[107], test[107], chg;
vector<string> v;
string s, a = "", b = "", c = "", d = "";
int main() {
	IOS;
	cin >> n;
	for (int i = 0; i < 2 * n - 2; ++i) {
		cin >> s;
		v.push_back(s);
		if (s.size() == n - 1) {
			if (a == "") {
				a = s;
			}
			else {
				b = s;
			}
		}
		if (s.size() == 1) {
			if (c == "") {
				c = s;
			}
			else {
				d = s;
			}
		}
	}
	for (int i = 0; i < 2 * n - 2 && chg == 0; ++i) {
		if (v[i] == a.substr(0, v[i].size()) && test[(int)v[i].size()] <= 0) {
			test[(int)v[i].size()] = 1;
		}
		else {
			if (v[i] != b.substr(n - 1 - v[i].size(), v[i].size()) || test[(int)v[i].size()] == -1) {
				chg = 1;
			}
			test[(int)v[i].size()] = -1;
		}
	}
	if (chg == 1) {
		s = a;
		a = b;
		b = s;
	}
	for (int i = 0; i < 2 * n - 2; ++i) {
		if (v[i] == a.substr(0, v[i].size()) && was[(int)v[i].size()] == 0) {
			cout << "P";
			was[(int)v[i].size()] = 1;
		}
		else {
			cout << "S";
		}
	}
	return 0;
}
*/



/*
//1092B
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int n, ans;
vector<int> a(107);
int main() {
	IOS;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	sort(a.begin(), a.begin() + n);
	for (int i = 0; i < n; i = i + 2) {
		ans += (a[i + 1] - a[i]);
	}
	cout << ans;
	return 0;
}
*/

/*
//1092A
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int n, k, t;
string s;
int main() {
	IOS;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		cin >> n >> k;
		s = "";
		for (int j = 0; j < n; ++j) {
			s += ('a' + j % k);
		}
		std::cout << s << "\n";
	}

	return 0;
}
*/


/*
//1031B
#include <iostream>
#include <vector>

std::vector<int> ans;
int n, a[100007], b[100007], t[100007][4];
int main() {
	std::cin >> n;
	for (int i = 0; i < n - 1; ++i) {
		std::cin >> a[i];
	}
	for (int i = 0; i < n - 1; ++i) {
		std::cin >> b[i];
		for (int j = 0; j < 4; ++j) {
			t[i + 1][j] = -1;
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < 4; ++j) {
			if (t[i][j] >= 0) {
				for (int k = 0; k < 4; ++k) {
					if (a[i] == (j | k) && b[i] == (j & k)) {
						t[i + 1][k] = j;
					}
				}
			}
		}
	}
	for (int j = 0; j < 4; ++j) {
		if (t[n - 1][j] >= 0) {
			std::cout << "YES\n";
			for (int i = n - 1; i >= 0; --i) {
				ans.push_back(j);
				j = t[i][j];
			}
			for (int i = ans.size() - 1; i >= 0; --i) {
				std::cout << ans[i] << " ";
			}
			return 0;
		}
	}
	std::cout << "NO";
}
*/

/*
//1080C
#include <iostream>
#include <vector>
#include <algorithm>

int t;
std::vector< long long > ans[2];
std::pair<long long, long long> squer(int a, int b, int c, int d) {
	if (a > c || b > d) {
		return std::pair<long long, long long>(0, 0);
	}
	long long x = 0, y = 0;
	x = ((long long)(c - a + 1 + 1) / 2) * ((d - b + 1 + 1) / 2);
	x += ((long long)(c - a + 1) / 2) * ((d - b + 1) / 2);
	y = ((long long)(c - a + 1 + 1) / 2) * ((d - b + 1) / 2);
	y += ((long long)(c - a + 1) / 2) * ((d - b + 1 + 1) / 2);
	if ((a + b) % 2) {
		return std::pair<long long, long long>(y, x);
	}
	return std::pair<long long, long long>(x, y);
}

int main() {
	std::cin >> t;
	for (int i = 0; i < t; ++i) {
		int n, m, x1, x2, x3, x4, y1, y2, y3, y4;
		std::cin >> n >> m >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;

		std::pair<long long, long long> a, b, c, d;
		a = squer(1, 1, n, m);
		b = squer(x1, y1, x2, y2);
		c = squer(x3, y3, x4, y4);
		d = squer(std::max(x1, x3), std::max(y1, y3), std::min(x2, x4), std::min(y2, y4));
		ans[0].push_back(a.first + b.second - c.first - d.second);
		ans[1].push_back((long long)n*m - ans[0][i]);
	}
	for (int i = 0; i < t; ++i) {
		std::cout << ans[0][i] << " " << ans[1][i] << "\n";
	}
}
*/

/*
//1082C
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

int n, m, s, r, ans, lans, mx, mdec;
std::vector< std::vector< int > > v(100000);
std::vector< int > w(100000);
std::queue < int > q;
int main() {
	std::cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		std::cin >> s >> r;
		v[s - 1].push_back(r);
	}
	for (int i = 0; i < m; ++i) {
		std::sort(v[i].begin(), v[i].end(), [](int x, int y) {return x > y; });
		mx = std::max(mx, (int)v[i].size());
		if (v[i].size() > 0 && v[i][0] > 0) {
			q.push(i);
		}
		else {
			++mdec;
		}
	}
	m -= mdec;
	mdec = 0;
	for (int i = 0; i < mx; ++i) {
		for (int j = 0; j < m; ++j) {
			int it = q.front();
			q.pop();

			if (v[it].size() > i && v[it][i] + w[it] > 0) {
				lans += v[it][i];
				w[it] += v[it][i];
				q.push(it);
			}
			else {
				lans -= w[it];
				++mdec;
			}
		}
		m -= mdec;
		mdec = 0;
		if (lans > ans) {
			ans = lans;
		}
	}
	std::cout << ans;
}
*/

/*
//1090A
#include <iostream>
#include <vector>
#include <algorithm>

int n, t, mx;
std::vector< std::pair<int, int> > m;
long long ans;
int main() {
	std::cin >> n;
	for (int i = 0; i < n; ++i) {
		std::cin >> t;
		m.push_back(std::make_pair(0, t));
		for (int j = 0; j < m[i].second; ++j) {
			std::cin >> t;
			m[i].first = std::max(m[i].first, t);
			mx = std::max(mx, t);
		}
	}
	for (auto el : m) {
		ans += (mx - el.first)*el.second;
	}
	std::cout << ans;
}
*/

/*
//967A
#include <iostream>

int n, s, h, m, old, ansh, ansm;
bool was;
int main() {
	std::cin >> n >> s;
	old = -s - 1;
	for (int i = 0; i < n; ++i) {
		std::cin >> h >> m;
		if (! was && h * 60 + m - old > s * 2 + 1) {
			ansh = (old + s + 1) / 60;
			ansm = (old + s + 1) % 60;
			was = true;
		}
		old = h * 60 + m;
	}
	if (!was) {
		ansh = (old + s + 1) / 60;
		ansm = (old + s + 1) % 60;
	}
	std::cout << ansh << " " << ansm;
}
*/

/*
//967B
#include <iostream>
#include <vector>
#include <algorithm>

int n, A, B, S, i;
std::vector< int > s(100007);
int main() {
	std::cin >> n >> A >> B;
	for (i = 0; i < n; ++i) {
		std::cin >> s[i];
		S += s[i];
	}
	std::sort(s.begin() + 1, s.begin() + n);

	while (s[0] * A < (long long)S * B) {
		S -= s[--i];
	}

	std::cout << n - i;
}
*/

/*
//910B
#include <iostream>
#include <vector>
#include <algorithm>

int n, a, b, ost, ans, lans;
std::vector< int > v(6);

void make(std::vector< int > v) {
	for (int i = 0; i < v.size(); ++i) {
		if (ost >= v[i]) {
			if (v.size() == 1) {
				ans = std::min(ans, lans);
			}
			else {
				ost -= v[i];
				std::vector< int > w;
				for (int j = 0; j < v.size(); ++j) {
					if (j != i) {
						w.push_back(v[j]);
					}
				}
				make(w);
				ost += v[i];
			}
		}
		else {
			int old_ost = ost;
			ost = n - v[i];
			++lans;

			if (v.size() == 1) {
				ans = std::min(ans, lans);
			}
			else {
				std::vector< int > w;
				for (int j = 0; j < v.size(); ++j) {
					if (j != i) {
						w.push_back(v[j]);
					}
				}
				make(w);
			}

			--lans;
			ost = old_ost;
		}
	}
}

int main() {
	std::cin >> n >> a >> b;

	ost = n;
	lans = 1;
	ans = 6;
	make({ a, a, a, a, b, b });
	std::cout << ans;
}
*/

/*
//910A
#include <iostream>
#include <string>
#include <algorithm>

int n, d, x, y, ans;
std::string s;
int main() {
	std::cin >> n >> d >> s;
	--n;
	while (x < n) {
		for (y = std::min(n, x + d); y > x; --y) {
			if (s[y] == '1') {
				break;
			}
		}
		if (y == x) {
			break;
		}
		x = y;
		++ans;
	}
	if (x == n) {
		std::cout << ans;
	}
	else {
		std::cout << -1;
	}
}
*/

/*
//903C
#include <iostream>
#include <map>
#include <algorithm>
int n, t, ans;
std::map< int, int > a;
int main() {
	std::cin >> n;
	for (int i = 0; i < n; ++i) {
		std::cin >> t;
		++a[t];
	}
	for (auto el : a) {
		ans = std::max(ans, el.second);
	}
	std::cout << ans;
}
*/

/*
//898E
#include <iostream>
#include <vector>
#include <algorithm>>

int n, it;
std::vector< int > a(200007);
std::vector< std::pair< int, bool > > b;
long long ans;
int main() {
	std::cin >> n;
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
	}
	std::sort(a.begin(), a.begin() + n);

	for (int i = 0; i < n; ++i) {
		while (it*it < a[i]) ++it;
		b.push_back(std::make_pair(std::min(it*it - a[i], std::abs(a[i] - (it - 1)*(it - 1))), a[i] != 0));
	}
	std::sort(b.begin(), b.end());

	for (int i = 0; i < n / 2; ++i) {
		ans += b[i].first;
	}
	if (!ans) {
		for (int i = n / 2; i < n; ++i) {
			if (!b[i].first) {
				ans += 1 + (b[i].second + 1) % 2;

			}
		}
	}

	std::cout << ans;
}
*/

/*
//901A
#include <iostream>

int h, a[100007], st;
int main() {
	std::cin >> h;
	for (int i = 0; i <= h; ++i) {
		std::cin >> a[i];
		if (a[i] > 1 && a[i-1] > 1) {
			++st;
		}
	}

	if (st < 1) {
		std::cout << "perfect";
	}
	else {
		std::cout << "ambiguous\n";
		int v = 0;
		for (int i = 0; i <= h; ++i) {
			for (int j = 0; j < a[i]; ++j) {
				std::cout << v << " ";
			}
			v += a[i];
		}
		v = 0;
		std::cout << "\n";
		for (int i = 0; i <= h; ++i) {
			for (int j = 0; j < a[i]; ++j) {
				std::cout << (j > 0 && a[i] > 1 && a[i - 1] > 1 ? v - 1 : v) << " ";
			}
			v += a[i];
		}
	}
}
*/

/*
//875B
#include <iostream>
#include <vector>

int n, p, a[300007], r, it;
std::vector< int > v;
int main() {
	std::cin >> n;
	it = n;
	v.push_back(0 - r + 1);
	for (int i = 1; i <= n; ++i) {
		std::cin >> p;
		a[p] = 1;
		while (a[it] == 1) {
			--it;
			++r;
		}
		v.push_back(i - r + 1);
	}

	for (auto el : v) {
		std::cout << el << " ";
	}
}
*/

/*
//864D
#include <iostream>

int n, a[200007], b[200007], ans, it = 1, was[200007];
int main() {
	std::cin >> n;
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
		++b[a[i]];
	}
	for (int i = 0; i < n; ++i) {
		if (b[a[i]] != 1) {
			while (b[it]) ++it;

			if (it < a[i] || was[a[i]]) {
				++ans;
				--b[a[i]];
				++b[it];
				a[i] = it;
			}
			else {
				was[a[i]] = true;
			}
		}
	}

	std::cout << ans << "\n";
	for (int i = 0; i < n; ++i) {
		std::cout << a[i] << " ";
	}
}
*/

/*
//856A
#include <iostream>

const int inf = 1000007;
int t, n, temp, a[107];
bool was[inf];
int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(0);
	std::cin >> t;
	for (int i_t = 0; i_t < t; ++i_t) {
		int nb = 0;
		std::cin >> n;

		for (int i = 0; i < n; ++i) {
			std::cin >> a[i];
		}
		for (int i = 0; i < inf; ++i) {
			was[i] = false;
		}

		std::cout << "YES\n";
		for (int i = 1;nb < n;++i) {
			if (!was[i]) {
				++nb;
				std::cout << i << " ";
				for (int j = 0; j < n; ++j) {
					for (int k = 0; k < n; ++k) {
						if (i + a[j] - a[k] > 0) {
							was[i + a[j] - a[k]] = true;
						}
					}
				}
			}
		}
		std::cout << "\n";
	}
}
*/

/*
//851B
#include <iostream>

int a[2], b[2], c[2];
long long line(long long x1, long long y1, long long x2, long long y2) {
	return (x1 - x2)*(x1 - x2) + (y1 - y2) * (y1 - y2);
}
bool tr() {
	if (a[0] - b[0] == 0 && a[0] - c[0] == 0)
		return false;
	if (a[0] - b[0] == 0 || a[0] - c[0] == 0)
		return true;
	if (((double)a[1] - b[1]) / (a[0] - b[0]) == ((double)a[1] - c[1]) / (a[0] - c[0]))
		return false;
	return true;
}
int main() {
	std::cin >> a[0] >> a[1] >> b[0] >> b[1] >> c[0] >> c[1];
	std::cout << (tr() && line(a[0], a[1], b[0], b[1]) == line(b[0], b[1], c[0], c[1]) ? "Yes" : "No");
}
*/

/*
//848A
#include <iostream>

const int inf = 100007;
int k, e[inf], i, j;
int main() {
	std::cin >> k;
	for (i = 1; e[i-1] < k; ++i) {
		e[i] = e[i - 1] + i;
	}
	--i;
	if (!k) std::cout << 'a';
	while (k) {
		while (e[i] > k) {
			--i;
		}
		for (int p = 0; p <= i; ++p) {
			std::cout << (char)('a' + j);
		}
		++j;
		k -= e[i];
	}
}
*/

/*
//845C
#include <iostream>
#include <vector>
#include <algorithm>

int n, l, r, st;
bool ok = true;
std::vector < std::pair< int, int > > a;
int main() {
	std::cin >> n;
	for (int i = 0; i < n; ++i) {
		std::cin >> l >> r;
		a.push_back(std::make_pair(l, -1));
		a.push_back(std::make_pair(r, 1));
	}
	std::sort(a.begin(), a.end());

	for (int i = 0; i < 2 * n && ok; ++i) {
		st += a[i].second;
		if (st < -2) ok = false;
	}

	std::cout << (ok ? "YES" : "NO");
}
*/

/*
//845B
#include <iostream>
#include <algorithm>

int a[6], ans = 6;
char q;
int main() {
	for (int i = 0; i < 6; ++i) {
		std::cin >> q;
		a[i] = q - '0';
	}

	for (int i0 = 0; i0 < 10; ++i0) {
		for (int i1 = 0; i1 < 10; ++i1) {
			for (int i2 = 0; i2 < 10; ++i2) {
				for (int i3 = 0; i3 < 10; ++i3) {
					for (int i4 = 0; i4 < 10; ++i4) {
						for (int i5 = 0; i5 < 10; ++i5) {
							if (i0 + i1 + i2 == i3 + i4 + i5) {
								ans = std::min(ans,
									1 * (i0 != a[0]) +
									1 * (i1 != a[1]) +
									1 * (i2 != a[2]) +
									1 * (i3 != a[3]) +
									1 * (i4 != a[4]) +
									1 * (i5 != a[5]));
							}
						}
					}
				}
			}
		}
	}

	std::cout << ans;
}
*/

/*
//1090M
#include <iostream>
#include <algorithm>
int n, k, a, b, ans, lans;
int main() {
	std::cin >> n >> k;
	for (int i = 0; i < n; ++i) {
		std::cin >> a;
		if (a == b) {
			ans = std::max(ans, lans);
			lans = 1;
		}
		else {
			++lans;
		}
		b = a;
	}
	ans = std::max(ans, lans);

	std::cout << ans;
}
*/

/*
//843A
#include <iostream>
#include <vector>
#include <algorithm>

int n;
std::vector< std::pair< int, int > > a(100007);
std::vector< std::vector< int > > ans;
bool was[100007];
int main() {
	std::cin >> n;
	for (int i = 1; i <= n; ++i) {
		std::cin >> a[i].first;
		a[i].second = i;
	}

	std::sort(a.begin() + 1, a.begin() + n + 1);

	for (int i = 1; i <= n; ++i) {
		if (!was[i]) {
			int it = i;
			std::vector< int > l;

			do {
				was[it] = true;
				l.push_back(it);
				it = a[it].second;
			} while (!was[it]);

			ans.push_back(l);
		}
	}

	std::cout << ans.size();
	for (auto v : ans) {
		std::cout << "\n" << v.size();
		for (auto el : v) {
			std::cout << " " << el;
		}
	}
}
*/

/*
//844B
#include <iostream>

int n, m, a[57][57];
long long n2[57], r[57], c[57], ans;
int main() {
	std::cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			std::cin >> a[i][j];
		}
	}

	n2[1] = 1;
	for (int i = 2; i < 52; ++i) {
		n2[i] = n2[i - 1] * 2;
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			r[i] += a[i][j];
			c[j] += a[i][j];
		}
	}

	for (int i = 0; i < n; ++i) {
		ans += n2[r[i] + 1] - 1 + n2[m - r[i] + 1] - 1;
	}
	for (int j = 0; j < m; ++j) {
		ans += n2[c[j] + 1] - 1 + n2[n - c[j] + 1] - 1;
	}

	std::cout << ans - n * m;
}
*/

/*
//845A
#include <iostream>
#include <vector>
#include <algorithm>

int n, t;
std::vector< int > a;
int main() {
	std::cin >> n;
	for (int i = 0; i < 2 * n; ++i) {
		std::cin >> t;
		a.push_back(t);
	}
	std::sort(a.begin(), a.end());

	if (a[n - 1] == a[n]) {
		std::cout << "NO";
	}
	else {
		std::cout << "YES";
	}
}
*/

/*
//844A
#include <iostream>
#include <string>
#include <set>

int k, ost, ans;
std::string s;
std::set< int > st;
int main() {
	std::cin >> s >> k;
	for (int i = 0; i < s.size(); ++i) {
		if (st.count(s[i])) {
			++ost;
		}
		else {
			st.insert(s[i]);
		}
	}

	if (st.size() + ost < k) {
		std::cout << "impossible";
	}
	else if (st.size() < k) {
		std::cout << k - st.size();
	}
	else {
		std::cout << 0;
	}
}
*/

/*
//1088C
#include <iostream>

int n, a[2007];
int main() {
	std::cin >> n;
	for (int i = 1; i <= n; ++i) {
		std::cin >> a[i];
	}
	std::cout << n + 1 << "\n";
	std::cout << "1 " << n << " 10000\n";
	for (int i = 1; i <= n; ++i) {
		std::cout << "2 " << i << " " << a[i] + 10000 - i << "\n";
	}
}
*/

/*
//1084C
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

const int inf = 1000000007;

string s;
int n, temp, ans[100007][2], ANS, one, n2[100007];
vector< int > a;
int main() {
	IOS;
	cin >> s;

	//s = "";
	//for (int i = 0; i < 50000; ++i) {
	//	s += "ab";
	//}
	n = s.length();

	for (int i = 0; i < n; ++i) {
		if (s[i] == 'b' && temp > 0) {
			if (temp == 1) {
				++one;
			}
			else {
				a.push_back(temp);
			}
			temp = 0;
		}
		else if (s[i] == 'a') {
			++temp;
		}
	}
	if (temp > 0) {
		if (temp == 1) {
			++one;
		}
		else {
			a.push_back(temp);
		}
	}

	int n = a.size();

	ans[0][0] = 1;
	ans[0][1] = 1;

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= i; ++j) {
			ans[j][i % 2] = ((long long)ans[j - 1][(i + 1) % 2] * a[i - 1] + ans[j][(i + 1) % 2]) % inf;
		}
	}

	for (int i = 1; i <= n; ++i) {
		ANS = (ANS + ans[i][n % 2]) % inf;
	}

	n2[0] = 1;
	for (int i = 1; i <= one; ++i) {
		n2[i] = (n2[i - 1] * 2) % inf;
	}
	ANS = ((long long)(ANS + 1)*n2[one] - 1) % inf;

	cout << ANS;

	return 0;
}
*/


/*
//1084B
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

long long n, s, sm, mn, b;
vector< int > v(1007);
int main() {
	IOS;
	cin >> n >> s;
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
		sm += v[i];
	}
	if (s > sm) {
		cout << -1;
	}
	else {
		mn = *min_element(v.begin(), v.begin() + n);
		b = (sm - s) / n;
		cout << min(b, mn);
	}
	return 0;
}
*/


/*
//1084A
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int n, ans;
vector < int > a(107);
int main() {
	IOS;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	for (int x = 0; x < n; ++x) {
		int lans = 0;
		for (int i = 1; i < n; ++i) {
			lans += a[i] * 4 * i;
		}
		ans = max(ans, lans);
	}
	cout << ans;
	return 0;
}
*/


/*
//499C
#include <iostream>

using namespace std;
int main() {
	long long x1, x2, y1, y2, a, b, c, n, ans = 0;

	cin >> x1 >> y1 >> x2 >> y2 >> n;

	for (int i = 0; i < n; ++i) {
		cin >> a >> b >> c;
		if ((a*x1 + b * y1 + c > 0) != (a*x2 + b * y2 + c > 0)) {
			ans++;
		}
	}

	cout << ans;
}
*/

/*
//499C
#include <iostream>

long long x[2], y[2], a, b, c, n, ans;


int main() {
	std::cin >> x[0] >> y[0] >> x[1] >> y[1] >> n;
	for (int i = 0; i < n; ++i) {
		std::cin >> a >> b >> c;
		long long t0 = a * y[0] + b * x[0] + c;
		long long t1 = a * y[1] + b * x[1] + c;
		if (t0 > 0 && t1 < 0) ++ans;
		if (t0 < 0 && t1 > 0) ++ans;
	}

	std::cout << ans;
}
*/

/*
//172E
#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <vector>
#include <stack>

std::string BHTML, BCSS;
int m, hash_iter, n, mn;
std::map< std::string, int > hash;
std::vector< int > text, x(207);

int hashTag(std::string const &tag) {
	if (!hash.count(tag)) {
		hash[tag] = ++hash_iter;
	}
	return hash[tag];
}

void addHash(std::string &tag) {
	bool opening = true, closing = false;

	if (tag[tag.length() - 1] == '/') {
		opening = true; closing = true;
		tag = tag.substr(0, tag.length() - 1);
	}
	else if (tag[0] == '/') {
		opening = false, closing = true;
		tag = tag.substr(1);
	}
	int code = hashTag(tag);

	if (opening) {
		text.push_back(code);
		++n;
	}
	if (closing) {
		text.push_back(-code);
		++n;
	}
}

void hashText() {
	int it, old = 0;

	while ((it = BHTML.find(">", old + 1)) != -1) {
		std::string tag = BHTML.substr(old + 1, it - old - 1);
		addHash(tag);

		old = it + 1;
	}
}

void getBCSS() {
	std::getline(std::cin, BCSS);
	std::stringstream ccin(BCSS);
	std::string tag;
	mn = 0;

	while (ccin >> tag) {
		x[mn++] = hashTag(tag);
	}
}

int countAns() {
	int ans = 0, it = 0;
	std::stack< bool > was;

	for (int i = 0; i < n; ++i) {
		if (text[i] > 0) {
			if (it < mn && text[i] == x[it]) {
				++it;
				was.push(true);
			}
			else {
				was.push(false);
			}

			if (it == mn && text[i] == x[mn - 1]) {
				++ans;
			}
		}
		else {
			if (was.top()) {
				--it;
			}
			was.pop();
		}
	}
	return ans;
}

int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(0);

	std::cin >> BHTML >> m;
	std::getline(std::cin, BCSS);

	hashText();

	for (int i = 0; i < m; ++i) {
		getBCSS();

		std::cout << countAns() << "\n";
	}
}
*/

/*
//WRONG
//172E
#include <iostream>
#include <string>
#include <sstream>
#include <set>
#include <map>
#include <vector>

std::string BHTML, BCSS;
int m, n, ans;

struct list {
	list(std::string const &_name, list *_parent)
		:name(_name), parent(_parent) {}
	std::string name;
	//std::map< std::string, std::set < list* > > childs;
	list *parent;

	bool operator< (list const &oth) const { return true; }
};
list tree("", 0);

std::map< std::string, std::set< list* > > mp;
std::vector< std::string > x(207);

void makeLists() {
	int it, old = 0;

	list *val = &tree;

	while ((it = BHTML.find(">", old + 1)) != -1) {
		std::string tag = BHTML.substr(old+1, it - old - 1);

		if (tag[it - old - 2] == '/') {
			std::string tagNewName = tag.substr(0, it - old - 2);
			list *listNew = new list(tagNewName, val);
			mp[tagNewName].insert(listNew);
			//val->childs[tagNewName].insert(listNew);
		}
		else if (tag[0] == '/') {
			val = val->parent;
		}
		else {
			std::string tagNewName = tag.substr(0, it - old - 1);
			list *listNew = new list(tagNewName, val);
			mp[tagNewName].insert(listNew);
			//val->childs[tagNewName].insert(listNew);
			val = listNew;
		}

		old = it + 1;
	}
}

int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(0);

	std::cin >> BHTML >> m;
	std::getline(std::cin, BCSS);

	makeLists();


	for (int i = 0; i < m; ++i) {
		std::getline(std::cin, BCSS);
		std::stringstream ccin(BCSS);
		n = 0, ans = 0;

		while (ccin >> x[n]) {
			++n;
		}

		if (mp.count(x[n - 1])) {
			for (auto el : mp[x[n - 1]]) {
				list *it = el;
				bool ok = true;
				for (int i = n - 2; i >= 0; --i) {
					if (it->parent != 0 && it->parent->name == x[i]) {
						it = it->parent;
					}
					else {
						ok = false;
						break;
					}
				}
				if (ok) {
					++ans;
				}
			}
		}

		std::cout << ans << "\n";
	}
}
*/

/*
//1088B
#include <iostream>
#include <vector>
#include <algorithm>

int n, k, it, sm;
std::vector<int> a(100007);
int main() {
	std::cin >> n >> k;
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
	}

	std::sort(a.begin(), a.begin() + n);

	while (it < n && a[it] == 0) {
		++it;
	}

	for (int i = 0; i < k; ++i) {
		while (it < n && a[it] == a[it + 1]) {
			++it;
		}
		if (it < n) {
			std::cout << a[it] - sm << "\n";
			sm = a[it];
			++it;
		}
		else {
			std::cout << 0 << "\n";
		}
	}
}
*/

/*
//1088A
#include <iostream>

int x;
int main() {
	std::cin >> x;
	if (x < 2) {
		std::cout << -1;
	}
	else {
		std::cout << x << " " << x;
	}
}
*/

/*
//854C
#include <iostream>
#include <queue>

int n, k, ans[300007];
struct data {
	int pos;
	int val;
	bool operator<(data const &oth) const {
		return this->val < oth.val;
	}
}c[300007];
std::priority_queue< data > q;
long long ansC;


int main() {
	std::cin >> n >> k;
	for (int i = 0; i < n; ++i) {
		std::cin >> c[i].val;
		c[i].pos = i + 1;
	}

	for (int i = 0; i < k; ++i) {
		q.push(c[i]);
	}

	for (int i = k; i < n + k; ++i) {
		if (i < n) {
			q.push(c[i]);
		}

		data el = q.top();
		q.pop();

		ans[el.pos] = i + 1;
		ansC += (long long)el.val * (i + 1 - el.pos);
	}

	std::cout << ansC << "\n";
	for (int i = 1; i <= n; ++i) {
		std::cout << ans[i] << " ";
	}
}
*/

/*
//180C
#include <iostream>
#include <string>
#include <algorithm>

int n, l[100007], r[100007], ans = 100007;
std::string s;
int main() {
	std::cin >> s;
	n = s.size();
	s = 'A' + s + 'a';

	for (int i = 1; i <= n; ++i) {
		l[i] = l[i - 1] + 1 * (s[i] >= 'a' && s[i] <= 'z');
	}
	for (int i = n; i > 0; --i) {
		r[i] = r[i + 1] + 1 * (s[i] >= 'A' && s[i] <= 'Z');
	}

	for (int i = 1; i <= n; ++i) {
		ans = std::min(ans, l[i] + r[i] - 1);
	}

	std::cout << ans;
}
*/

/*
//371B
#include <iostream>
#include <map>
#include <algorithm>

int a, b;
std::map<int, int> ma, mb;

int make(int &a, int const &d) {
	int rez = 0;
	if (!a)
		return rez;
	while (a%d == 0) {
		++rez;
		a /= d;
	}
	return rez;
}
int main() {
	std::cin >> a >> b;

	ma[2] = make(a, 2);	ma[3] = make(a, 3);	ma[5] = make(a, 5);
	mb[2] = make(b, 2);	mb[3] = make(b, 3);	mb[5] = make(b, 5);

	if (a != b) {
		std::cout << -1;
	}
	else {
		std::cout << std::abs(ma[2] - mb[2]) + std::abs(ma[3] - mb[3]) + std::abs(ma[5] - mb[5]);
	}
}
*/

/*
//1082B
#include <iostream>
#include <string>
#include <algorithm>

int n, it, ans1, ans2;
std::string s, sr;
int main() {
	std::cin >> n >> s;
	sr = s;
	std::reverse(sr.begin(), sr.end());

	while ((it = s.find("GSG", it)) != -1) {
		++it;
		int lans = 1, i = it - 1, j = it + 1;
		for (; i >= 0 && s[i] != 'S'; --i) {
			++lans;
		}
		for (; j < n && s[j] != 'S'; ++j) {
			++lans;
		}
		if (s.find("G", j) == -1 && sr.find("G", n - 1 - i) == -1) {
			--lans;
		}

		//int a1 = s.find("G", j);
		//int a2 = sr.find("G", n - 1 - i);
		ans1 = std::max(ans1, lans);
	}

	int kusk = 0;
	for (int i = 0; i < n; ++i) {
		if (s[i] == 'G') {
			++kusk;
			int lans = 1;
			while (i < n - 1 && s[i+1] == 'G') {
				++lans;
				++i;
			}
			ans2 = std::max(ans2, lans);
		}
	}
	if (kusk > 1) {
		++ans2;
	}

	std::cout << std::max(ans1, ans2);
}
*/

/*
//1089G
#include <iostream>

int t, k, a[7], b, ans;
int main() {
	std::cin >> t;
	for (int i = 0; i < t; ++i) {
		std::cin >> k;

		b = 0;
		for (int j = 0; j < 7; ++j) {
			std::cin >> a[j];
			b += a[j];
		}

		ans = k / b * 7;

		k -= k / b * b;
		if (ans > 0) {
			ans -= 7;
			k += b;
		}

		bool end = false;
		for (int st = 1; st < 14 && !end; ++st) {
			for (int j = 0; j < 14; ++j) {
				int oneW = 0;
				for (int p = j - 6; p < j - 6 + st; ++p) {
					oneW += a[(p + 7) % 7];
				}
				if (oneW == k) {
					ans += st;
					end = true;
					break;
				}
			}
		}

		std::cout << ans << "\n";
	}
}
*/

/*
//1089L
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

int n, k, a[100007], b[100007], ansCnt;
long long ans;
std::map< int, std::vector < int > > m;
std::vector < int > ansV;
int main() {
	std::cin >> n >> k;
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
	}
	for (int i = 0; i < n; ++i) {
		std::cin >> b[i];
	}

	for (int i = 0; i < n; ++i) {
		m[a[i]].push_back(b[i]);
	}

	ansCnt = k - m.size();

	for (auto el : m) {
		int imx = std::max_element(el.second.begin(), el.second.end()) - el.second.begin();

		for (int i = 0; i < el.second.size(); ++i) {
			if (i != imx) {
				ansV.push_back(el.second[i]);
			}
		}
	}

	std::sort(ansV.begin(), ansV.end());

	for (int i = 0; i < ansCnt; ++i) {
		ans += ansV[i];
	}

	std::cout << ans;
}
*/

/*
#include <iostream>
#include <algorithm>

int t, n, x, y, d, ans;
int main() {
	std::cin >> t;
	for (int i = 0; i < t; ++i) {
		std::cin >> n >> x >> y >> d;
		if (std::abs(y - x) % d == 0) {
			ans = std::abs(y - x) / d;
		}
		else if ((y - 1) % d == 0) {
			ans = x / d + (x % d > 1 ? 1 : 0);
			ans += (y - 1) / d;
			if ((n - y) % d == 0) {
				int ans2 = (n - x + 1) / d + ((n - x + 1) % d > 1 ? 1 : 0);
				ans2 += (n - y) / d;
				ans = std::min(ans, ans2);
			}
		}
		else if ((n - y) % d == 0) {
			ans = (n - x + 1) / d + ((n - x + 1) % d > 1 ? 1 : 0);
			ans += (n - y) / d;
		}
		else {
			ans = -1;
		}
		std::cout << ans << "\n";
	}
}
*/

/*
//1061B
#include <iostream>
#include <vector>
#include <algorithm>

int n, m;
std::vector<int> a(100007);
long long ans;
int main() {
	std::cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		std::cin >> a[i];
		ans += a[i];
	}
	std::sort(a.begin() + 1, a.begin() + n + 1);


	int add = 0;
	int prev = 0;
	for (int i = 1; i <= n; ++i) {
		++add;
		if (a[i] > prev)
			++prev;
	}
	ans -= a[n] - prev + add;

	std::cout << ans;
}
*/

/*
//1077D
#include <iostream>
#include <vector>
#include <algorithm>

const int inf = 2000007;
int n, k, t, l, r;
std::vector< int > v(inf), ans;

bool make(int cnt) {
	ans.clear();
	int sz = 0;
	for (int i = 0; i < inf && sz < k; ++i) {
		int add = std::min(v[i] / cnt, k - sz);
		for (int j = 0; j < add; ++j) {
			ans.push_back(i);
			++sz;
		}
	}
	return sz == k;
}

int main() {
	std::cin >> n >> k;
	for (int i = 0; i < n; ++i) {
		std::cin >> t;
		++v[t];
	}

	l = 0, r = n;
	while (r - l > 1) {
		int mid = (r + l) / 2;
		if (make(mid)) {
			l = mid;
		}
		else {
			r = mid;
		}
	}
	if (!make(r)) make(l);

	for (auto el : ans) {
		std::cout << el << " ";
	}
}
*/

/*
//1056D
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int n, a;
map<int, set<int> > p;
vector<int> ans(100007);
bool was[100007];

int make(int it) {
	was[it] = true;
	if (p[it].size() <= 1 && it != 1) {
		return 1;
	}

	int sm = 0;
	for (auto el : p[it]) {
		if (!was[el]) {
			ans[el] = make(el);
			sm += ans[el];
		}
	}

	return max(sm, 1);
}


int main() {
	IOS;

	cin >> n;
	for (int i = 2; i <= n; ++i) {
		cin >> a;
		p[a].insert(i);
		p[i].insert(a);
	}

	ans[1] = make(1);
	sort(ans.begin() + 1, ans.begin() + n + 1);

	for (int i = 1; i <= n; ++i) {
		cout << ans[i] << " ";
	}

	return 0;
}
*/



/*
//1056C
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int n, m, a, b, t, x, y, itp1, itp;
vector < pair<int, int> > p, p1;
map <int, int> pm;
bool was[2007];

bool cmp(pair<int,int> const &a, pair<int, int> const &b) {
	return a.first > b.first;
}

void printme(int a) {
	cout << a << "\n";
	cout.flush();
	was[a] = true;
}


int main() {
	IOS;
	cin >> n >> m;
	for (int i = 1; i <= n * 2; ++i) {
		int temp;
		cin >> temp;
		p.push_back(make_pair(temp, i));
	}
	for (int i = 1; i <= m; ++i) {
		cin >> a >> b;
		pm[a] = b;
		pm[b] = a;

		if (p[a-1].first != p[b-1].first) {
			if (p[a-1].first > p[b-1].first) {
				p1.push_back(make_pair(p[a-1].first, a));
			}
			else {
				p1.push_back(make_pair(p[b-1].first, b));
			}
		}
	}
	cin >> t;

	sort(p.begin(), p.end(), cmp);
	sort(p1.begin(), p1.end(), cmp);

	if (t != 1) {
		t = 0;
	}

	for (int i = 0,j = 0; i < n || j < n;) {
		if (!t) {
			++i;
			cin >> y;
			if (y == -1) {
				return 0;
			}
			was[y] = true;
		}
		else
		{
			++j;
			if (pm.count(y) && !was[pm[y]]) {
				printme(pm[y]);
			}
			else {
				while (itp1 < p1.size() && was[p1[itp1].second]) {
					++itp1;
				}
				if (itp1 < p1.size()) {
					printme(p1[itp1].second);
				}
				else {
					while (was[p[itp].second]) {
						++itp;
					}
					printme(p[itp].second);
				}
			}
		}
		t = (t + 1) % 2;
	}

	return 0;
}
*/


/*
//1056B
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int n, m, a[1007][1007];
long long ans, ans1, ans2;
int main() {
	IOS;
	cin >> n >> m;

	for (int i = 1; i <= min(m, n); ++i) {
		for (int j = 1; j <= min(m, n); ++j) {
			if ((i*i + j * j) % m == 0) {
				a[i][j] = 1;
				++ans;
			}
		}
	}
	if (n <= m) {
		cout << ans;
		return 0;
	}
	ans *= (long long)(n / m) * (n / m);

	for (int i = 1; i <= n % m; ++i) {
		for (int j = 1; j <= m; ++j) {
			ans1 += a[i][j];
		}
	}
	ans1 *= (long long)(n / m) * 2;

	for (int i = 1; i <= n % m; ++i) {
		for (int j = 1; j <= n % m; ++j) {
			ans2 += a[i][j];
		}
	}

	ans += ans1 + ans2;

	cout << ans;

	return 0;
}
*/

/*
//1056A
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int n, ans[107], c, t;
int main() {
	IOS;

	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> c;
		for (int j = 0; j < c; ++j) {
			cin >> t;
			++ans[t];
		}
	}

	for (int i = 1; i <= 100; ++i) {
		if (ans[i] == n) {
			cout << i << " ";
		}
	}

	return 0;
}
*/




/*
//1080B
#include <iostream>

int q, l, r, ans;
int main() {
	std::cin >> q;
	for (int i = 0; i < q; ++i) {
		std::cin >> l >> r;
		if (l % 2) {
			if (r % 2) {
				ans = (r - l) / 2 - r;
			}
			else {
				ans = (r - l + 1) / 2;
			}
		}
		else {
			if (r % 2) {
				ans = -(r - l + 1) / 2;
			}
			else {
				ans = -(r - l) / 2 + r;
			}
		}
		std::cout << ans << "\n";
	}
}
*/

/*
//1080A
#include <iostream>

int n, k;
int f(int a) {
	int b = n * a;
	return b / k + (b%k ? 1 : 0);
}

int main() {
	std::cin >> n >> k;
	std::cout << f(2) + f(5) + f(8);
}
*/

/*
//1061A
#include <iostream>

int n, s;
int main() {
	std::cin >> n >> s;
	std::cout << s / n + (s%n ? 1 : 0);
}
*/

/*
//1062C
#include <iostream>
const int inf = 1000000007;
long long n, q, l, r, x[100007], sm, xl[100007],xr[100007], x2[100007];
int main() {
	std::cin >> n >> q;
	for (int i = 1; i <= n; ++i) {
		char q;
		std::cin >> q;
		x[i] = q - '0';
		sm += x[i];
		xl[i] = xl[i - 1] + x[i];
	}

	for (int i = n; i > 0; --i) {
		xr[i] = xr[i + 1] + x[i];
	}

	x2[1] = 1;
	for (int i = 2; i <= n; ++i) {
		x2[i] = ((x2[i - 1] + 1) * 2 - 1) % inf;
	}

	for (int i = 0; i < q; ++i) {
		std::cin >> l >> r;

		long long x1 = xl[r] + xr[l] - sm;
		long long x0 = r - l + 1 - x1;

		long long ans = ((long long)x2[x1] * (x2[x0] + 1)) % inf;
		std::cout << ans << "\n";
	}
}
*/

/*
//1062B
#include <iostream>
#include <map>
#include <algorithm>
#include <set>

int n, ans, k;
std::map <int, int> m;
std::set <int> s;
int main() {
	std::cin >> n;

	for (int i = 2; i*i <= n; ++i) {
		if (n%i == 0) {
			++m[i];
			n /= i;
			--i;
		}
	}
	if (m.size()) {
		++m[n];
		ans = 1;

		for (auto el : m) {
			s.insert(el.second);
		}
		if (s.size() == 1) {
			int lk = 0, k2 = 1;
			while (m.begin()->second > k2) {
				++lk;
				k2 *= 2;
			}
			if (k2 == m.begin()->second) {
				for (auto el : m) {
					ans *= el.first;
				}
				std::cout << ans << " " << lk;
				return 0;
			}
		}
	}
	else {
		std::cout << n << " 0";
		return 0;
	}

	for (auto el : m) {
		ans *= el.first;

		int lk = 1, k2 = 1;
		while (el.second > k2) {
			++lk;
			k2 *= 2;
		}
		k = std::max(k, lk);
	}
	std::cout << ans << " " << k;
}
*/

/*
//1062A
#include <iostream>
#include <algorithm>

int n, a[107], ans, lans;
int main() {
	std::cin >> n;
	for (int i = 1; i <= n; ++i) {
		std::cin >> a[i];
	}
	a[n + 1] = 1001;
	a[n + 2] = 1001;
	for (int i = 0; i < n; ++i) {
		if (a[i + 2] - a[i] <= 2) {
			++lans;
		}
		else {
			ans = std::max(ans, lans);
			lans = 0;
		}
	}
	std::cout << std::max(ans, lans);
}
*/

/*
//1077C
#include <iostream>
#include <vector>
#include <algorithm>

int n;
std::vector< std::pair< int, int > > a(200007);
std::vector< int > ans;
long long sm = 0;
int main() {
	std::cin >> n;
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i].first;
		a[i].second = i + 1;
		sm += a[i].first;
	}
	std::sort(a.begin(), a.begin() + n);

	for (int i = 0; i < n - 1; ++i) {
		if (sm - a[i].first == a[n - 1].first * 2) {
			ans.push_back(a[i].second);
		}
	}
	if (sm - a[n - 1].first == a[n - 2].first * 2) {
		ans.push_back(a[n-1].second);
	}
	std::cout << ans.size() << "\n";
	for (auto el : ans) {
		std::cout << el << " ";
	}
}
*/

/*
//1077B
#include <iostream>
#include <string>

int n, a[107], ans;
std::string s = "";

int main() {
	std::cin >> n;
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
		s += (a[i] ? '1' : '0');
	}
	int it;
	while ((it = s.find("10101")) != -1) {
		std::cout << s << "\n";
		s.replace(it, 5, "10001");
		++ans;
	}
	while ((it = s.find("101")) != -1) {
		std::cout << s << "\n";
		s.replace(it, 3, "100");
		++ans;
	}
	std::cout << s << "\n";
	std::cout << ans;
}
*/

/*
//1077A
#include <iostream>

long long t, x, a, b, k;
int main() {
	std::cin >> t;
	for (int i = 0; i < t; ++i) {
		std::cin >> a >> b >> k;
		std::cout << ( (a - b)*(k / 2) + a * (k % 2) ) << "\n";
	}
}
*/

/*
//stepik
// Эти классы реализовывать заново не нужно
#include <iostream>
#include <string>

struct ICloneable
{
	virtual ICloneable* clone() const = 0;
	virtual ~ICloneable() { }
};

// Поле data_ типа T в классе ValueHolder
// открыто, к нему можно обращаться
template <typename T>
struct ValueHolder : ICloneable
{
	ValueHolder(T const &el) :data_(el) {}
	T data_;
	ICloneable* clone() const {
		ICloneable *temp = new ValueHolder<T>(data_);
		return temp;
	}
};

// Это класс, который вам нужно реализовать
class Any
{
public:
	// В классе Any должен быть конструктор,
	// который можно вызвать без параметров,
	// чтобы работал следующий код:
	//    Any empty; // empty ничего не хранит
	Any() :ptr(0) {}


	// В классе Any должен быть шаблонный
	// конструктор от одного параметра, чтобы
	// можно было создавать объекты типа Any,
	// например, следующим образом:
	//    Any i(10); // i хранит значение 10
	template <typename T>
	Any(T const &a) :ptr(new ValueHolder < T >(a)) {}


	// Не забудьте про деструктор. Все выделенные
	// ресурсы нужно освободить.
	~Any() { delete ptr; }


	// В классе Any также должен быть конструктор
	// копирования (вам поможет метод clone
	// интерфейса ICloneable)
	Any(Any const &oth) {
		if (oth.ptr == 0) {
			ptr = 0;
		}
		else {
			ptr = oth.ptr->clone();
		}
	}

	// В классе должен быть оператор присваивания и/или
	// шаблонный оператор присваивания, чтобы работал
	// следующий код:
	//    Any copy(i); // copy хранит 10, как и i
	//    empty = copy; // empty хранит 10, как и copy
	//    empty = 0; // а теперь empty хранит 0
	Any& operator=(Any const &oth) {
		if (this != &oth) {
			delete ptr;

			if (oth.ptr == 0) {
				ptr = 0;
			}
			else {
				ptr = oth.ptr->clone();
			}
		}
		return *this;
	}


	// Ну и наконец, мы хотим уметь получать хранимое
	// значение, для этого определите в классе Any
	// шаблонный метод cast, который возвращает
	// указатель на хранимое значение, или нулевой
	// указатель в случае несоответствия типов или
	// если объект Any ничего не хранит:
	//    int *iptr = i.cast<int>(); // *iptr == 10
	//    char *cptr = i.cast<char>(); // cptr == 0,
	//        // потому что i хранит int, а не char
	//    Any empty2;
	//    int *p = empty2.cast<int>(); // p == 0
	// При реализации используйте оператор dynamic_cast.
	//
	// Допустим у вас есть два наследника класса Base: Derived1
	// и Derived2. Кроме того у вас есть указать baseptr
	// типа Base*. Как проверить указывает ли этот указатель на
	// самом деле на объект класса Derived1 или на объект
	// класса Derived2? Для этого можно воспользоваться dynamic_cast-ом:
	//
	// Derived1 *derived1ptr = dynamic_cast<Derived1*>(baseptr);
	//
	// Если derived1ptr не равен 0, то  baseptr на самом деле
	// указывал на объект класса Derived1, если же derivedptr равен 0,
	// то baseptr на самом деле указывал на объкт какого-то другого
	// класса (например, Derived2). Это можно проверить так:
	//
	// Derived2 *derived2ptr = dynamic_cast<Derived2*>(baseptr);
	//
	// dynamic_cast работает только, если в классе есть хотя бы
	// один виртуальный метод, и в шаблоне ValueHolder такой
	// как раз имеется.
	template <typename T>
	T* cast() {
		if (ptr == 0)
			return 0;
		ValueHolder<T> *rez = dynamic_cast<ValueHolder<T>*>(ptr);
		if (rez == nullptr)
			return 0;
		//T *ans = new T(rez->data_);
		return &rez->data_;
	}

private:

	ICloneable *ptr;
};

template <typename T, typename U>
struct SameType {
	static const bool value = 0;
};
template <typename T>
struct SameType<T, T> {
	static const bool value = 1;
};

template <class T, size_t N>
size_t array_size(T(&a)[N]) {
	return N;
}

int main() {
	//struct Dummy { };
	//typedef int type;
	//std::cout << SameType<int, int>::value << std::endl; // выведет 1, т. е. true
	//std::cout << SameType<int, type>::value << std::endl; // 1, type == int
	//std::cout << SameType<int, int&>::value << std::endl; // 0, int и ссылка на int - различные типы
	//std::cout << SameType<Dummy, Dummy>::value << std::endl; // 1
	//std::cout << SameType<int, const int>::value << std::endl; // 0, const - часть типа

	int ints[] = { 1, 2, 3, 4 };
	int *iptr = ints;
	double doubles[] = { 3.14 };
	std::cout << array_size(ints) << "\n"; // вернет 4
	std::cout << array_size(doubles); // вернет 1
	//array_size(iptr); // тут должна произойти ошибка компиляции

	//int *i = new int(4);
	//ICloneable *a = new ValueHolder < int > (*i);
	//ValueHolder < int > *b = new (I;
	{
		std::string s = "fs";
		Any d(s);

		Any empty;
		int i = 10;
		Any copy(i); // copy хранит 10, как и i
		empty = copy; // empty хранит 10, как и copy
		empty = 0; // а теперь empty хранит 0


		int *iptr = copy.cast<int>(); // *iptr == 10
		char *cptr = copy.cast<char>(); // cptr == 0,
			// потому что i хранит int, а не char
		Any empty2;
		int *p = empty2.cast<int>(); // p == 0

		//std::cout << *iptr;
		//delete iptr;
		//delete cptr;
		//delete p;
	}

	std::cout << "\n";
	if (_CrtDumpMemoryLeaks())
		std::cout << "memory leak is detected" << std::endl;
	else
		std::cout << "no memory leaks" << std::endl;
}
*/

/*
//1076D
//WRONG
#include <iostream>
#include <map>
#include <set>
#include <queue>

int n, m, k, x, y, w, d[300007];
std::map< int, int > mp[300007];
std::set< int > sp;
int dp[300007];
std::queue
void make(int a, int deep) {
	if (dp[a] < deep)
		return;
	dp[a] = deep;

	for (auto el : mp[a]) {
		make(el.first, deep + 1);
	}
}

int main() {
	std::cin >> n >> m >> k;
	for (int i = 0; i < m; ++i) {
		std::cin >> x >> y >> w;
		mp[x][y] = w;
		mp[y][x] = w;
	}

	dp[1] = 0;
	for (auto el : mp[1]) {

		if ()
		for (auto el1 : mp[el.first]) {

		}

	}

	int mx = 0, it = 0;
	for (auto el : mp[1]) {
		int lk = 0;
		for (auto el1 : mp[el.first])
		if (mp[el.first].size() > mx) {
			it = el.first;
			mx = mp[el.first].size();
		}
	}
}
*/

/*
//1076C
#include <iostream>
#include <algorithm>

int t, d;
double x, y;
int main() {
	std::cin >> t;
	for (int i = 0; i < t; ++i) {
		std::cin >> d;

		if (d*d - 4 * d < 0) {
			std::cout << "N\n";
		}
		else {
			x = (d + sqrt(d*d - 4 * d)) / 2;
			y = (d - sqrt(d*d - 4 * d)) / 2;

			std::cout.precision(12);
			std::cout << "Y " << x << " " << y << "\n";
		}
	}
}
*/

/*
//1076B
#include <iostream>
#include <algorithm>

long long simple(long long a) {
	for (long long i = 2; i*i <= a; ++i) {
		if (a%i == 0) {
			return i;
		}
	}
	return a;
}

long long n, ans, simp;
int main() {
	std::cin >> n;
	simp = simple(n);

	while (simp != 2 && simp != n) {
		int temp = simp;
		simp = simple(n / simp - 1);
		n -= temp;
		++ans;
	}
	ans += n / simp;

	std::cout << ans;
}
*/

/*
//1076A
#include <iostream>
#include <string>

int n;
std::string s;
int main() {
	std::cin >> n >> s;
	for (int i = 1; i < n; ++i) {
		if (s[i] < s[i - 1]) {
			std::cout << s.substr(0, i - 1) + s.substr(i);
			return 0;
		}
	}
	std::cout << s.substr(0, s.size() - 1);
}
*/

/*
//1066F
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

bool cmp(std::pair< int, int > const &a, std::pair< int, int> const &b) {
	if (a.first == b.first) {
		return a.second > b.second;
	}
	return a.first < b.first;
}

long long dist(std::pair< int, int > const &a, std::pair< int, int> const &b) {
	return (long long)std::abs(a.first - b.first) + std::abs(a.second - b.second);
}

const long long inf = 1e18;

int n, x, y;
std::map< int, long long[2] > dp;
//std::map < int, std::vector< std::pair< int, int > > > m;
std::map < int, std::pair< std::pair< int, int >, std::pair< int, int > > > mm;
int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);

	std::cin >> n;
	for (int i = 0; i < n; ++i) {
		std::cin >> x >> y;

		int Lv = std::max(x, y);
		std::pair< int, int > el = std::make_pair(x, y);

		if (mm.count(Lv)) {
			if (cmp(el, mm[Lv].first)) {
				mm[Lv].first = el;
			}
			else if (cmp(mm[Lv].second, el)) {
				mm[Lv].second = el;
			}
		}
		else {
			mm[Lv].first = el;
			mm[Lv].second = el;
		}

		//m[std::max(x, y)].push_back(std::make_pair(x, y));
	}

	//m[0].push_back(std::make_pair(0, 0));
	mm[0].first = mm[0].second = std::make_pair(0, 0);
	dp[0][0] = dp[0][1] = 0;
	int oLv = 0;

	for (auto v : mm) {
		if (v.first == 0)
			continue;

		//std::sort(v.second.begin(), v.second.end(), cmp);

		int Lv = v.first;
		//long long fe = dist(*v.second.begin(), *v.second.rbegin());
		long long fe = dist(v.second.first, v.second.second);

		//mm[Lv].first = *v.second.begin();
		//mm[Lv].second = *v.second.rbegin();

		dp[Lv][0] = inf;
		dp[Lv][0] = std::min(dp[Lv][0], dp[oLv][0] + fe +
			dist(mm[oLv].first, v.second.second) );
		dp[Lv][0] = std::min(dp[Lv][0], dp[oLv][1] + fe +
			dist(mm[oLv].second, v.second.second));

		dp[Lv][1] = inf;
		dp[Lv][1] = std::min(dp[Lv][1], dp[oLv][0] + fe +
			dist(mm[oLv].first, v.second.first));
		dp[Lv][1] = std::min(dp[Lv][1], dp[oLv][1] + fe +
			dist(mm[oLv].second, v.second.first));

		oLv = Lv;
	}

	std::cout << std::min(dp[oLv][0], dp[oLv][1]);
}
*/

/*
//1066D
#include <iostream>

int n, m, k, a[200007], ans, kr;
int main() {
	std::cin >> n >> m >> k;
	for (int i = n - 1; i >= 0; --i) {
		std::cin >> a[i];
	}

	kr = k;
	for (int i = 0; i < n; ++i) {
		if (kr >= a[i]) {
			kr -= a[i];
		}
		else {
			if (m == 1) {
				std::cout << i;
				return 0;
			}
			else {
				kr = k - a[i];
				--m;
			}
		}
	}
	std::cout << n;
}
*/

/*
//1055B
#include <iostream>

int n, m, l, ans;
long long a[100007];
int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);

	std::cin >> n >> m >> l;
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
	}
	for (int i = 0; i < n; ++i) {
		if ((a[i] > l) != (a[i - 1] > l) && a[i] > l) {
			++ans;
		}
	}

	for (int i = 0; i < m; ++i) {
		int type, p, d;
		std::cin >> type;
		if (type) {
			std::cin >> p >> d;
			--p;
			if (a[p] <= l && a[p] + d > l) {
				if (p == 0 && a[p + 1] <= l) {
					++ans;
				}
				else
				if (p == n - 1 && a[p - 1] <= l) {
					++ans;
				}
				else
				if ((p > 0 && a[p - 1] <= l) && (p < n - 1 && a[p + 1] <= l)) {
					++ans;
				}
				else
				if ((p > 0 && a[p - 1] > l) && a[p + 1] > l) {
					--ans;
				}
			}
			a[p] += d;
		}
		else {
			std::cout << ans << "\n";
		}
	}
}
*/

/*
//1055A
#include <iostream>

int n, s, a[1007], b[1007];
int main() {
	std::cin >> n >> s;
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
	}
	for (int i = 0; i < n; ++i) {
		std::cin >> b[i];
	}
	--s;
	if (a[0] == 0) {
		std::cout << "NO";
	}
	else {
		if (a[s] == 1) {
			std::cout << "YES";
		}
		else {
			bool ok = false;
			for (int i = s + 1; i < n && !ok; ++i) {
				if (a[i] == 1 && b[i] == 1) {
					ok = true;
				}
			}
			if (ok && b[s] == 1) {
				std::cout << "YES";
			}
			else {
				std::cout << "NO";
			}
		}
	}
}
*/

/*
//1066E
#include <iostream>
#include <string>

const int inf = 998244353;
int n, m, B[200007], ans;
long long p2 = 1;
std::string a, b;
int main() {
	std::cin >> n >> m >> a >> b;
	if (n > m) {
		a = a.substr(a.size() - b.size());
		n = m;
	}

	for (int i = 0; i <= m-n; ++i) {
		B[0] += 1 * (b[i]-'0');
	}
	for (int i = 1; i < n; ++i) {
		B[i] = B[i - 1] + 1 * (b[m - n + i] - '0');
	}

	for (int i = n-1; i >= 0; --i) {
		ans = (p2 * (a[i] == '1') * B[i] + ans)%inf;
		p2 = (p2 * 2) % inf;
	}
	std::cout << ans;
}
*/

/*
//stepik
#include <iostream>
struct ICloneable
{
	virtual ICloneable* clone() const = 0;
	virtual ~ICloneable() { }
};

// Шаблон ValueHolder с типовым параметром T,
// должен содержать одно открытое поле data_
// типа T.
//
// В шаблоне ValueHolder должен быть определен
// конструктор от одного параметра типа T,
// который инициализирует поле data_.
//
// Шаблон ValueHolder должен реализовывать
// интерфейс ICloneable, и возвращать указатель
// на копию объекта, созданную в куче, из метода
// clone.

template <typename T, class U>
struct ValueHolder : ICloneable
{
	ValueHolder(T const &el) :data_(el) {}
	T data_;
	ICloneable* clone() const override {
		ICloneable *data2 = new T(data_);
		return data2;
	}
};


template <typename T>
class Array
{
public:
	// Список операций:
	//
	explicit Array(size_t size, const T& value = T()) : cnt(size), arr(0) {
		arr = static_cast<T*>(operator new[](cnt * sizeof(T)));

		for (size_t i = 0; i < cnt; ++i) {
			new (arr + i) T(value);
		}
	}
	//   конструктор класса, который создает
	//   Array размера size, заполненный значениями
	//   value типа T. Если у класса нет конструктора
	//   по умолчанию, то второй аргумент этого конструктора
	//   обязателен.
	//
	Array() : cnt(0), arr(0) {}
	//   конструктор класса, который можно вызвать
	//   без параметров. Должен создавать пустой
	//   Array.
	//
	// Array(const Array &)
	Array(Array const &oth) : cnt(oth.cnt), arr(0) {
		arr = static_cast<T*>(operator new[](cnt * sizeof(T)));

		for (size_t i = 0; i < cnt; ++i) {
			new (arr + i) T(oth.arr[i]);
		}
	}
	//   конструктор копирования, который создает
	//   копию параметра. Для типа T оператор
	//   присваивания не определен.
	//
	// ~Array()
	~Array() {
		for (int i = 0; i < cnt; ++i) {
			arr[i].~T();
		}
		operator delete[](arr);
	}
	//   деструктор, если он вам необходим.
	//
	// Array& operator=(...)
	Array& operator=(Array<T> const &oth) {
		if (&oth != this) {
			this->~Array();
			cnt = oth.cnt;
			arr = static_cast<T*>(operator new[](cnt * sizeof(T)));

			for (size_t i = 0; i < cnt; ++i) {
				new (arr + i) T(oth.arr[i]);
			}
		}
		return *this;
	}
	//   оператор присваивания.
	//
	size_t size() const {
		return cnt;
	}
	//   возвращает размер массива (количество
	//                              элементов).
	//
	T& operator[](size_t it) {
		return arr[it];
	}
	// const T& operator[](size_t) const
	//   две версии оператора доступа по индексу.
private:
	size_t cnt;
	T *arr;
};

class A {
public:
	explicit A(int a) :el(a) {}
	explicit A(A const &a) :el(a.el) {}
	int get() { return el; }
	~A() {
		int i = 0;
	}
private:
	A() {}
	A& operator=(A const &a) {}
	int el;
};

int main() {
	A a(1);
	A b(a);
	A *c = new A(5);

	Array<A> *mas = new Array<A>(5,*c);
	Array<A> *mas1 = new Array<A>();
	Array<A> *mas2 = new Array<A>(*mas1);
	*mas1 = *mas;
	*mas = *mas2;

	std::cout << a.get() << " " << b.get() << " " << c->get();
	delete c;
	delete mas;
	delete mas1;
	delete mas2;


	std::cout << "\n";
	if (_CrtDumpMemoryLeaks())
		std::cout << "memory leak is detected" << std::endl;
	else
		std::cout << "no memory leaks" << std::endl;
}
*/

/*
//1073D
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <list>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

bool cmp(int a, int b) {
	return a > b;
}

int sz;
long long n, T, sm, ans;
vector <int> a(200007);
list < int > l;
int main() {
	IOS;
	cin >> n >> T;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		sm += a[i];
		l.push_back(a[i]);
	}

	auto it = l.begin();
	sz = n;
	while (sz > 0) {
		ans += T / sm * sz;
		T %= sm;

		while (sz > 0 && T < sm) {
			if (*it <= T) {
				T -= *it;
				++ans;
				if (T == 0) {
					sz = 0;
					break;
				}
				++it;
			}
			else {
				sm -= *it;
				auto temp = it++;
				l.erase(temp);
				--sz;
			}
			if (it == l.end()) {
				it = l.begin();
			}
		}
	}

	cout << ans;

	return 0;
}
*/

/*
//1046C
#include <iostream>
#include <vector>
#include <algorithm>

int n, d, ans;
std::vector < int > s(200007), p(200007);
int main() {
	std::cin >> n >> d;
	for (int i = 0; i < n; ++i) {
		std::cin >> s[i];
	}
	for (int i = 0; i < n; ++i) {
		std::cin >> p[i];
	}

	--d;
	for (int i = 0, r = n - 1; i < n; ++i) {
		if (i != d) {
			if (s[i] + p[r] <= s[d] + p[0]) {
				--r;
			}
			else {
				++ans;
			}
		}
	}
	std::cout << ++ans;
}
*/

/*
//1075B
#include <iostream>
#include <vector>;

int n, m, x[200007], t[200007], ans[200007];
std::vector< int > a, b;
int main() {
	std::cin >> n >> m;
	for (int i = 0; i < n + m; ++i) {
		std::cin >> x[i];
	}
	for (int i = 0; i < n + m; ++i) {
		std::cin >> t[i];
		if (t[i]) {
			a.push_back(x[i]);
		}
		else {
			b.push_back(x[i]);
		}
	}

	int i = 0, j = 0, sza = a.size(), szb = b.size();
	while (i < sza - 1) {
		while (j < szb && a[i + 1] - b[j] >= b[j] - a[i]) {
			++ans[i];
			++j;
		}
		++i;
	}
	while (j++ < szb) {
		++ans[i];
	}

	for (int i = 0; i < sza; ++i) {
		std::cout << ans[i] << " ";
	}
}
*/

/*
//1075A
#include <iostream>
#include <algorithm>

long long n, x, y;
int main() {
	std::cin >> n >> x >> y;

	if (std::max(x - 1, y - 1) <= std::max(n - x, n - y)) {
		std::cout << "White";
	}
	else {
		std::cout << "Black";
	}
}
*/

/*
//1046F
#include <iostream>
#include <vector>

int n, x, f;
std::vector < int > a(200007);
long long ans;

int main() {
	std::cin >> n;
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
	}
	std::cin >> x >> f;

	for (int i = 0; i < n; ++i) {
		ans += a[i] / (x + f) * f;
		if (a[i] % (x + f) > x)
			ans += f;
	}

	std::cout << ans;
}
*/

/*
//1043C
#include <iostream>
#include <string>
#include <algorithm>

std::string s;
int main() {
	std::cin >> s;
	for (int i = 0; i < s.size() - 1; ++i) {
		if (s[i] != s[i + 1]) {
			std::reverse(s.begin(), s.begin() + i);
			std::cout << "1 ";
		}
		else {
			std::cout << "0 ";
		}
	}
	std::cout << 1 * (s[s.size() - 1] == 'a');
}
*/

/*
//1043B
#include <iostream>
#include <vector>

int n, a[1007], ans;
std::vector< int > v;
int main() {
	std::cin >> n;
	for (int i = 1; i <= n; ++i) {
		std::cin >> a[i];
		a[i - 1] = a[i] - a[i - 1];
	}

	for (int i = 1; i <= n; ++i) {
		bool ok = true;
		for (int j = i; j < n; ++j) {
			if (a[j] != a[j%i]) {
				ok = false;
				break;
			}
		}
		if (ok) {
			++ans;
			v.push_back(i);
		}
	}

	std::cout << ans << "\n";
	for (auto el : v) {
		std::cout << el << " ";
	}
}
*/

/*
//1043A
#include <iostream>
#include <algorithm>

int n, k, a, sa, mxa;
int main() {
	std::cin >> n;
	for (int i = 0; i < n; ++i) {
		std::cin >> a;
		mxa = std::max(mxa, a);
		sa += a;
	}
	sa *= 2;
	k = std::max(mxa, sa / n + 1);
	std::cout << k;
}
*/

//if (_CrtDumpMemoryLeaks())
//std::cout << "memory leak is detected" << std::endl;
//else
//std::cout << "no memory leaks" << std::endl;


/*
//1070F
#include <iostream>
#include <vector>
#include <algorithm>

int n, ans;
std::vector < int > a[4];
//a[0] = 00
//a[1] = 01
//a[2] = 10
//a[3] = 11
int main() {
	std::cin >> n;
	for (int i = 0; i < n; ++i) {
		char q1, q2;
		int A;
		std::cin >> q1 >> q2 >> A;
		a[(q1 == '1') * 2 + (q2 == '1')].push_back(A);
	}
	for (auto el : a[3]) {
		ans += el;
	}
	for (int i = 1; i < 3; ++i) {
		std::sort(a[i].begin(), a[i].end(),
			[](const int& a, const int& b) -> bool { return a > b; }
		);
	}
	for (int i = 1; i < 3; ++i) {
		int j = 0;
		for (; j < std::min(a[1].size(), a[2].size()); ++j) {
			ans += a[i][j];
		}
		for (; j < a[i].size(); ++j) {
			a[0].push_back(a[i][j]);
		}
	}
	std::sort(a[0].begin(), a[0].end(),
		[](const int& a, const int& b) -> bool { return a > b; }
	);
	for (int i = 0; i < std::min(a[0].size(), a[3].size()); ++i) {
		ans += a[0][i];
	}

	std::cout << ans;
}
*/

/*
//Stepic
#include <iostream>

struct A {
	A(int a):a(a) {
		std::cout << a << " ";
	}
	int a;
	void print() {
		std::cout << a;
	}
	A &operator+() {
		return *this;
	}
};

void prin(A a) {
	a.print();
}

int main() {
	A a(1);
	prin(*(new A(2)));


}
*/

/*
//1070H
#include <iostream>
#include <string>
#include <map>
#include <set>

int n, q;
std::string s;
std::map <std::string, std::string> m;
std::map <std::string, std::set< std::string >> ms;

int main() {
	std::cin >> n;
	for (int i = 0; i < n; ++i) {
		std::cin >> s;

		for (int j = 1; j <= s.size(); ++j) {
			for (int k = 0; k <= s.size() - j; ++k) {
				std::string tStr = s.substr(k, j);
				m[tStr] = s;
				ms[tStr].insert(s);
			}
		}
	}
	std::cin >> q;
	for (int i = 0; i < q; ++i) {
		std::cin >> s;
		if (m.count(s)) {
			std::cout << ms[s].size() << " " << m[s] << "\n";
		}
		else {
			std::cout << "0 -\n";
		}
	}
}
*/

/*
//1070D
#include <iostream>

int n, k, a[200007], ost;
long long ans;
int main() {
	std::cin >> n >> k;
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
		int add = (a[i] + ost) / k;
		ans += add;
		if (add == 0 && ost > 0) {
			++ans;
			ost = 0;
		}
		else {
			ost = (a[i] + ost) % k;
		}
	}
	if (ost > 0)
		++ans;
	std::cout << ans;
}
*/

/*
//1070K
#include <iostream>

int n, k, a[100007], sm1;
int main() {
	std::cin >> n >> k;
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
	}

	for (int i = 0; i <= n - k; ++i) {
		sm1 += a[i];

		int j = i + 1, k1 = 1, sm2 = 0;

		for (; j < n && k1 < k;++j) {
			sm2 += a[j];

			if (sm2 == sm1) {
				++k1;
				sm2 = 0;
			}
			else if (sm2 > sm1) {
				break;
			}
		}

		if (j == n && k1 == k) {
			std::cout << "Yes\n" << i + 1;

			j = i + 1, sm2 = 0;
			int si = 0;

			for (; j < n; ++j) {
				++si;
				sm2 += a[j];

				if (sm2 == sm1) {
					std::cout << " " << si;
					sm2 = 0;
					si = 0;
				}
			}
			return 0;
		}
	}

	std::cout << "No";
}
*/

/*
//WRONG
//1073D
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <list>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

bool cmp(int a, int b) {
	return a > b;
}

int sz;
long long n, T, sm, ans;
vector <int> a(200007);
list < int > l;
int main() {
	IOS;
	cin >> n >> T;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		sm += a[i];
		l.push_back(a[i]);
	}

	//sort(a.begin(), a.end(), cmp);

	//for (int i = 0; i < n; ++i) {
	//	ans += T / sm * (n - i);
	//	T %= sm;
	//	sm -= a[i];
	//}

	auto it = l.begin();
	while ((sz = l.size()) > 0) {
		auto itL = it;
		long long smL = 0;

		ans += T / sm * sz;
		T %= sm;

		while (smL < T) {
			while (it != l.end() && *it < T && smL < T) {
				++it;
			}

			if (it == l.end() && !l.empty()) {
				it = l.begin();
			}
			else if (*it < T) {
				l.erase(it);
			}
		}
	}


	cout << ans;

	return 0;
}
*/


/*
//1073C
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int n, x, y, X, Y;
vector < char > a(200007);
int main() {
	IOS;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		switch (a[i]) {
		case 'U':	++Y;	break;
		case 'D':	--Y;	break;
		case 'L':	++X;	break;
		case 'R':	--X;	break;
		}
	}
	cin >> x >> y;

	if (abs(x) + abs(y) < n) {
		cout << -1;
		return 0;
	}





	return 0;
}
*/

/*
//1073B
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int n, top;
vector <int> a(200007), b(200007);
map <int, int> m;
int main() {
	IOS;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		m[a[i]] = i;
	}
	for (int i = 1; i <= n; ++i) {
		cin >> b[i];

		if (m[b[i]] < top) {
			cout << "0 ";
		}
		else {
			cout << m[b[i]] - top << " ";
			top = m[b[i]];
		}
	}

	return 0;
}
*/

/*
//1073A
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int n;
string s;
map <char, int> m;

bool ok(int n) {
	for (auto el : m) {
		if (el.second > n / 2)
			return false;
	}
	return true;
}

int main() {
	IOS;

	cin >> n >> s;
	for (int i = 0; i < n; ++i) {
		m.erase(m.begin(), m.end());

		for (int j = i; j < n; ++j) {
			++m[s[j]];
			if (ok(j - i + 1)) {
				cout << "YES\n" << s.substr(i,j-i+1);
				return 0;
			}
		}
	}

	cout << "NO\n";
	return 0;
}
*/

/*
//1068C
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

const int N = 107;
int n, m;
bool ans[N][5000];
int main() {
	IOS;

	cin >> n >> m;

	for (int i = 1; i <= n; ++i) {
		ans[i][i] = true;
	}

	for (int i = 1; i <= m; ++i) {
		int a, b;
		cin >> a >> b;
		ans[a][n + i] = true;
		ans[b][n + i] = true;
	}


	for (int i = 1; i <= n; ++i) {
		int cnt = 0;
		for (int j = 1; j <= n + m; ++j) {
			if (ans[i][j]) {
				++cnt;
			}
		}
		cout << cnt << "\n";
		for (int j = 1; j <= n + m; ++j) {
			if (ans[i][j]) {
				cout << i << " " << j << "\n";
			}
		}
	}


	return 0;
}
*/





/*
//1068B
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

long long a, b, ans;
int main() {
	IOS;

	cin >> b;

	for (long long i = 1; i*i <= b; ++i) {
		if (b%i == 0)
			if (b / i == i)
				++ans;
			else
				ans += 2;
	}
	cout << ans;

	return 0;
}
*/
