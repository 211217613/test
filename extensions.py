import requests


# Get html response from website

URL = "Enter url here or get from CLI"

res = requests.get(URL)
try:
    res.raise_for_status()
except Exception as exc:
    print('There was a problem downloading the page {}'.format(exc))

