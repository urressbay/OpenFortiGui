openfortigui_sources = [
  'main.c',
  'openfortigui-application.c',
  'openfortigui-window.c',
]

openfortigui_deps = [
  dependency('gtk4'),
  dependency('libadwaita-1', version: '>= 1.4'),
]

openfortigui_sources += gnome.compile_resources('openfortigui-resources',
  'openfortigui.gresource.xml',
  c_name: 'openfortigui'
)

executable('openfortigui', openfortigui_sources,
  dependencies: openfortigui_deps,
       install: true,
)
